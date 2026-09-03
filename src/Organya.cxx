#include "Organya.h"

#include <srl.hpp>

#include "CommonDefines.h"

#define PANDUMMY 0XFF
#define VOLDUMMY 0xFF
#define KEYDUMMY 0xFF

#define ALLOCNOTE 4096

#define DEFVOLUME 200
#define DEFPAN 6 

#define SETALL		0xffffffff
#define SETWAIT		0x00000001
#define SETGRID		0x00000002
#define SETALLOC	0x00000004
#define SETREPEAT	0x00000008
#define SETFREQ		0x00000010
#define SETWAVE		0x00000020
#define SETPIPI		0x00000040

// Below are Organya song data structures
typedef struct NOTELIST
{
	NOTELIST *from;	// Previous address
	NOTELIST *to;	// Next address

	long x;	// Position
	unsigned char length;	// Sound length
	unsigned char y;	// Sound height
	unsigned char volume;	// Volume
	unsigned char pan;
}NOTELIST;

// Track data * 8
typedef struct TRACKDATA
{
	unsigned short freq;	// Frequency (1000 is default)
	unsigned char wave_no;	// Waveform No.
	signed char pipi;

	NOTELIST *note_p;
	NOTELIST *note_list;
} TRACKDATA;

// Unique information held in songs
typedef struct MUSICINFO
{
	unsigned short wait;
	unsigned char line;	// Number of lines in one measure
	unsigned char dot;	// Number of dots per line
	unsigned short alloc_note;	// Number of allocated notes
	long repeat_x;	// Repeat
	long end_x;	// End of song (Return to repeat)
	TRACKDATA tdata[MAXTRACK];
} MUSICINFO;

// メインクラス。このアプリケーションの中心。（クラスってやつを初めて使う） (Main class. The heart of this application. (Class is used for the first time))
typedef struct OrgData
{
    OrgData();	// コンストラクタ (Constructor)
//	~OrgData();	// デストラクタ (Destructor)
	MUSICINFO info;
	char track;
	char mute[MAXTRACK];
	unsigned char def_pan;
	unsigned char def_volume;
	void InitOrgData(void);
	void GetMusicInfo(MUSICINFO *mi);	// 曲情報を取得 (Get song information)
	// 曲情報を設定。flagは設定アイテムを指定 (Set song information. flag specifies the setting item)
	bool SetMusicInfo(MUSICINFO *mi,unsigned long flag);
    bool NoteAlloc(unsigned short note_num);	// 指定の数だけNoteDataの領域を確保 (Allocate the specified number of NoteData areas.)
    void ReleaseNote(void);	// NoteDataを開放 (Release NoteData)
	// 以下は再生 (The following is playback)
	void PlayData(void);
	void SetPlayPointer(long x);	// 再生ポインターを指定の位置に設定 (Set playback pointer to specified position)
	// 以下はファイル関係 (The following are related to files)
	bool  InitMusicData(const char *path);
} ORGDATA;

AudioBackend_Sound *lpORGANBUFFER[8][8][2] = {NULL};

/////////////////////////////////////////////
//■オルガーニャ■■■■■■■■■■■■/////// (Organya)
/////////////////////

// Wave playing and loading
typedef struct
{
	short wave_size;
	short oct_par;
	short oct_size;
} OCTWAVE;

OCTWAVE oct_wave[8] =
{
	{ 256,  1,  4 }, // 0 Oct
	{ 256,  2,  8 }, // 1 Oct
	{ 128,  4, 12 }, // 2 Oct
	{ 128,  8, 16 }, // 3 Oct
	{  64, 16, 20 }, // 4 Oct
	{  32, 32, 24 }, // 5 Oct
	{  16, 64, 28 }, // 6 Oct
	{   8,128, 32 }, // 7 Oct
};

bool MakeSoundObject8(signed char *wavep, signed char track, signed char pipi)
{
    unsigned long i,j,k;
	unsigned long wav_tp;	// WAVテーブルをさすポインタ (Pointer to WAV table)
	unsigned long wave_size;	// 256;
	unsigned long data_size;
	unsigned char *wp;
	unsigned char *wp_sub;
	int work;

    for(j = 0; j < 8; j++)
    {
        for(k = 0; k < 2; k++)
        {
            wave_size = oct_wave[j].wave_size;
            
            if(pipi)
            {
                data_size = wave_size * oct_wave[j].oct_size;
            }
            else
            {
                data_size = wave_size;
            }

            wp = (unsigned char*)malloc(data_size);

            if(wp == NULL)
            {
                return false;
            }

            // Get wave data
            wp_sub = wp;
            wav_tp = 0;
            
            for(i = 0; i < data_size; i++)
            {
                work = *(wavep + wav_tp);
                work += 0x80;

                *wp_sub = (unsigned char)work;

                wav_tp += 0x100 / wave_size;
                if(wav_tp > 0xFF)
                {
                    wav_tp -+ 0x100;
                }

                wp_sub++;
            }

            lpORGANBUFFER[track][j][k] = AudioBackend_CreateSound(22050, wp, data_size);

            free(wp);

            if(lpORGANBUFFER[track][j][k] == NULL)
            {
                return false;
            }
            AudioBackend_RewindSound(lpORGANBUFFER[track][j][k]);
        }
    }

    return true;
}

short freq_tbl[12] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

void ChangeOrganFrequency(unsigned char key, signed char track, long a)
{
    if(!audio_backend_initialised)
    {
        return;
    }
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 2; i++)
        {
            AudioBackend_SetSoundFrequency(lpORGANBUFFER[track][j][i], ((oct_wave[j].wave_size * freq_tbl[key]) * oct_wave[j].oct_par) / 8 + (a - 1000));	// 1000を+αのデフォルト値とする (1000 is the default value for + α)
        }
    }
}

bool g_mute[MAXTRACK];
short pan_tbl[13] = {0, 43, 86, 129, 172, 215, 256, 297, 340, 383, 426, 469, 512};
unsigned char old_key[MAXTRACK] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};	// 再生中の音 (Sound being played)
unsigned char key_on[MAXTRACK];	// キースイッチ (Key switch)
unsigned char key_twin[MAXTRACK];	// 今使っているキー(連続時のノイズ防止の為に二つ用意) (Currently used keys (prepared for continuous noise prevention))

void ChangeOrganPan(unsigned char key, unsigned char pan, signed char track)	// 512がMAXで256がﾉｰﾏﾙ (512 is MAX and 256 is normal)
{
    if(!audio_backend_initialised)
    {
        return;
    }

    if(old_key[track] != KEYDUMMY)
    {
        AudioBackend_SetSoundPan(lpORGANBUFFER[track][old_key[track] / 12][key_twin[track]], (pan_tbl[pan] - 0x100) * 10);
    }
}

void ChangeOrganVolume(int no, long volume, signed char track)	// 300がMAXで300がﾉｰﾏﾙ (300 is MAX and 300 is normal)
(
    if(!audio_backend_initialised)
    {
        return;
    }
)