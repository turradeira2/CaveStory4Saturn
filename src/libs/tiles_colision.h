#include <srl.hpp>


uint8_t Solid[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t SlopeUpLeft[16] = {14,14,14,13,13,13,12,10, 9, 9, 9, 7, 5, 4, 4, 4};
uint8_t SlopeUpRight[16] = {14,14,14,13,13,13,12,10, 9, 9, 9, 7, 5, 4, 4, 4};



/*
COLISION TYPES
0 - EMPTY
1 - SOLID
2 - SLOPE UP LEFT
3 - SLOPE UP RIGHT
4 - SLOPE DOWN LEFT
5 - SLOPE DOWN RIGHT
6 - WATER
*/