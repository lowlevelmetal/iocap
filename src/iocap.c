/*
 * iocap
 * 
 * iocap.c
 * 03-14-2024
 */

// Unix includes
#include <signal.h>

// Standard includes
#include <stdlib.h>
#include <stdio.h>

// Local includes
#include "term.h"
#include "shared.h"
#include "signal.h"
#include "box.h"


int main() {
   puts("Launching iocap");
 
   // Setup signal handler
   if(signal(SIGINT, sig_handler) == SIG_ERR) {
      perror("Failed to setup signal handler");
      return EXIT_FAILURE;
   }

   // Set running flag
   atomic_store(&running, 1);

   // Setup terminal 
   init_term();
   if(set_term_mode(TERM_RAW) < 0) {
      perror("Failed to set terminal to raw mode");
      return EXIT_FAILURE;
   }

   if(clear_term() < 0) {
      perror("Failed to clear terminal");
      return EXIT_FAILURE;
   }

   coord2d top_left = {3,3};
   coord2d bottom_right = {48, 24};
   box *hbox = alloc_box(top_left, bottom_right);

   hbox->draw(hbox);

   // Main loop
   while(atomic_load(&running)) {
      
   }

   free_box(hbox);

   reset_term(); 

   return EXIT_SUCCESS; 
}
