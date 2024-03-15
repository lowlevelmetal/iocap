/*
 * iocap
 *
 * box.c
 * 03-15-2024
 */

// Standard includes
#include <string.h>

// Unix includes
#include <unistd.h>

// Local includes
#include "box.h"
#include "term.h"
#include "blocking_io.h"

// Privates
static int8_t _draw_hoz_line(uint16_t width) {
   for(int i = 0; i < width; i++) {
      if(block_write(STDOUT_FILENO, "#", 1) < 0)
         return -1;
   }

   return 0;
}

static int8_t _draw(const box * const hbox) {
   if(!hbox)
      return -1; 

   uint16_t width = hbox->bottom_right.x - hbox->top_left.x;

   // Set starting position for draw
   move_term_cursor(hbox->top_left.x, hbox->top_left.y);

   // Draw top line
   if(_draw_hoz_line(width) < 0)
      return -1;

   // Draw sides, line by line
   for(uint16_t i = hbox->top_left.y + 1; i < hbox->bottom_right.y; i++) {
      move_term_cursor(hbox->top_left.x, i);
      if(block_write(STDOUT_FILENO, "#", 1) < 0)
         return -1;

      move_term_cursor(hbox->bottom_right.x, i);
      if(block_write(STDOUT_FILENO, "#", 1) < 0)
         return -1;
   }

   move_term_cursor(hbox->top_left.x, hbox->bottom_right.y);

   // Draw bottom line
   if(_draw_hoz_line(width) < 0)
      return -1;

   return 0;
}

static void _draw_text(const box * const hbox, const char * const text, const coord2d pos_offset) {
   if(!hbox || !text)
      return;

   move_term_cursor(hbox->top_left.x + 1 + pos_offset.x, hbox->top_left.y + 1 + pos_offset.y);

   block_write(STDOUT_FILENO, text, strlen(text));
}

// Globals
box *alloc_box(coord2d top_left_coord, coord2d bottom_right_coord) {
   box *hbox = (box *)malloc(sizeof(box));
   if(hbox == NULL)
      return NULL;

   // Initialize object
   hbox->top_left = top_left_coord;
   hbox->bottom_right = bottom_right_coord;
   hbox->draw = _draw;
   hbox->draw_text = _draw_text;

   return hbox;
}

void free_box(box *hbox) {
   if(hbox)
      free(hbox);
}
