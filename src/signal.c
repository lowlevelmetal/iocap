/*
 * iocap
 *
 * signal.c
 * 03-15-2024
 */

// Standard includes
#include <stdlib.h>
#include <stdio.h>

// Unix includes
#include <signal.h>

// Local includes
#include "signal.h"
#include "shared.h"

void sig_handler(int sig) {
   switch(sig) {
      case SIGINT:
         puts("Sigint captured...");
         atomic_store(&running, 0); // Set the running state to false so the program can exit gracefully
         break;
      default:
        exit(EXIT_SUCCESS);
   }
}
