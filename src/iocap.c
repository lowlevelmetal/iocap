/*
 * iocap
 * 
 * iocap.c
 * 03-14-2024
 */

// Standard includes
#include <stdlib.h>
#include <stdio.h>

// Local includes
#include "term.h"
#include "shared.h"


int main() {
   puts("Launching iocap");
 
   // Set running flag
   atomic_store(&running, 1);

   // Setup terminal 
   init_term();
   if(set_term_mode(TERM_RAW) < 0) {
      perror("Failed to set terminal to raw mode");
      return EXIT_FAILURE;
   }

   // Main loop
   while(atomic_load(&running)) {

   }

   reset_term(); 

   return EXIT_SUCCESS; 
}
