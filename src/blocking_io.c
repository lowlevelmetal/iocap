/*
 * iocap
 *
 * blocking_io.c
 * 03-15-2024
 */

// Unix includes
#include <unistd.h>

// Local includes
#include "blocking_io.h"

// Block until write is complete
int8_t block_write(int fd, void *data, size_t size) {
   uint_fast64_t total = 0;

   do {
      int ret = write(fd, (void *)(((uint_fast64_t)data) + total), size - total);
      if(ret == -1)
         return -1;

      total += ret;

   } while (total < size);

   return 0;
}
