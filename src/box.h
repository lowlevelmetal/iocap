/*
 * iocap
 *
 * box.h
 * 03-15-2024
 */

#ifndef __BOX_H_
#define __BOX_H_

// Standard includes
#include <stdint.h>
#include <stdlib.h>

typedef struct coord2d {
   uint16_t x, y;
} coord2d;

typedef struct box {
   coord2d top_left, bottom_right;
   int8_t (* draw)(const struct box * const hbox);
   void (*draw_text)(const struct box * const hbox, const char * const text, const coord2d pos_offset);
} box;

box *alloc_box(coord2d top_left_coord, coord2d bottom_right_coord);
void free_box(box *hbox);

#endif
