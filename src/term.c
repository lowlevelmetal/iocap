/*
 * iocap
 *
 * term.c
 * 03-14-2024
 */

// Unix includes
#include <unistd.h>

// Local includes
#include "term.h"

// PRIVATES
static uint8_t initialized = 0;
static struct termios original, current;

static void _set_raw_mode() {
   current.c_lflag &= ~(ECHO | ICANON);
   tcsetattr(STDIN_FILENO, TCSAFLUSH, &current); 
}

// GLOBALS
void init_term() {
   if(initialized)
      return;

   // Get terminal configuration
   tcgetattr(STDIN_FILENO, &current);

   // Make a backup of current configuration
   original = current;

   // Set global initialized flag
   initialized = 1;
}

// If term was initialized, reset it to state before initialization
void reset_term() {
   if(initialized)
      tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

// Set terminal to MODE
int8_t set_term_mode(uint8_t mode) {
   if(!initialized)
      return -1;
   
   switch(mode) {
      case TERM_RAW:
         _set_raw_mode();
         break;
      default:
         return -2;
   }

   return 0;
}

