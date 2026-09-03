#include "ArmsItem.h"

#include <srl.hpp>

#include "CommonDefines.h"
#include "Draw.h"
//#include "Escape.h"
#include "Game.h"
//#include "KeyControl.h"
#include "Main.h"
//#include "Shoot.h"
//#include "Sound.h"
//#include "TextScr.h"

ARMS gArmsData[ARMS_MAX];
ITEM gItemData[ITEM_MAX];

int gSelectedArms;
int gSelectedItem;

int gCampTitleY;

/// True if we're in the items section of the inventory (not in the weapons section) (only relevant when the inventory is open)
bool gCampActive;

int gArmsEnergyX = 16;

void ClearArmsData(void)
{
    gSelectedArms = 0; // Should probably be done in order to avoid potential problems with the selected weapon being invalid (like is done in SubArmsData)
    gArmsEnergyX = 32;
	memset(gArmsData, 0, sizeof(gArmsData));
}

void ClearItemData(void)
{
	memset(gItemData, 0, sizeof(gItemData));
}

bool AddArmsData(long code, long max_num)
{
    // Search for code
	int i = 0;
    while(i < ARMS_MAX)
    {
        if(gArmsData[i].code == code)
        {
            break; // Found identical
        }
        if(gArmsData[i].code == 0)
        {
            break; // Found free slot
        }

        ++i;
    }
    
    if(i == ARMS_MAX)
    {
        return FALSE;	// No space left
    }

    if(gArmsData[i].code == 0)
    {
        // Initialize new weapon
		memset(&gArmsData[i], 0, sizeof(ARMS));
		gArmsData[i].level = 1;
    }

    // Set weapon and ammo
	gArmsData[i].code = code;
	gArmsData[i].max_num += max_num;
	gArmsData[i].num += max_num;

    // Cap the amount of current ammo to the maximum amount of ammo
	if (gArmsData[i].num > gArmsData[i].max_num)
    {
        gArmsData[i].num = gArmsData[i].max_num;
    }

    return true;
}

bool SubArmsData(long code)
{
    int i;

    for(i = 0; i < ARMS_MAX; ++i)
    {
        if(gArmsData[i].code == code)
        {
            break; // Found
        }
    }

    if(i == ARMS_MAX)
    {
        return false; // Not found
    }

    // Shift all arms from the right to the left
	for (++i; i < ARMS_MAX; ++i)
    {
        gArmsData[i - 1] = gArmsData[i];
    }

    // Clear farthest weapon and select first
	gArmsData[i - 1].code = 0;
	gSelectedArms = 0;

    return true;
}

bool TradeArms(long code1, long code2, long max_num)
{
    // Search for code1
	int i = 0;
    while(i < ARMS_MAX)
    {
        if(gArmsData[i].code == code1)
        {
            break; // Found identical
        }
        ++i;
    }

    if(i == ARMS_MAX)
    {
        return false; //Not found
    }

    // Initialize new weapon replacing old one, but adding the maximum ammunition to that of the old weapon.
	gArmsData[i].level = 1;
	gArmsData[i].code = code2;
	gArmsData[i].max_num += max_num;
	gArmsData[i].num += max_num;
	gArmsData[i].exp = 0;

    return true;
}

bool AddItemData(long code)
{
    // Search for code
    int i = 0;
    while(i < ITEM_MAX)
    {
        if(gItemData[i].code == code)
        {
            break; // Found Identical
        }
        if(gItemData[i].code == 0)
        {
            break; // Found free slot
        }

        ++i;
    }

    if(i == ITEM_MAX)
    {
        return false; // Not Found
    }

    gItemData[i].code = code;

    return true;
}

bool SubItemData(long code)
{
    // Search for code
	int i;
	for (i = 0; i < ITEM_MAX; ++i)
    {
        if (gItemData[i].code == code)
        {
            break; // Found
        }
    }

    if(i == ITEM_MAX)
    {
        return false; // Not Found
    }

    // Shift all items from the right to the left
    for (++i; i < ITEM_MAX; ++i)
    {
        gItemData[i - 1] = gItemData[i];
    }

    gItemData[i - 1].code = 0;
	gSelectedItem = 0;

    return true;
}

/// Update the inventory cursor
void MoveCampCursor(void)
{
    bool bChange;

    // Compute the current amount of weapons and items
	int arms_num = 0;
	int item_num = 0;
    while(gArmsData[arms_num].code != 0)
    {
        ++arms_num;
    }
    while(gItemData[item_num].code != 0)
    {
        ++item_num;
    }
    if(arms_num == 0 && item_num == 0)
    {
        return; //Empty inventory
    }

    // True if we're currently changing cursor position
    bChange = false;

    if(!gCampActive)
    {
        // Handle selected weapon
        if(gKeyTrg & gKeyLeft)
        {
            --gSelectedArms;
            bChange  = true;
        }
    }
}