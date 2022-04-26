#include "LIB_VRT_STD_TYPES.h"
#include "LIB_VRT_MAP.h"

s32 MAP_XY(s32 x1, s32 x2, s32 y1, s32 y2, s32 input)
{
    return (((y2 - y1) * (input - x1)) / (x2 - x1)) + y1;
}