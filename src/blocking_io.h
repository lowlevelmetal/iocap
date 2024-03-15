/*
 * iocap
 *
 * blocking_io.h
 * 03-15-2024
 */

#ifndef __BLOCKING_IO_H_
#define __BLOCKING_IO_H_

// Standard includes
#include <stdint.h>
#include <stddef.h>

// Block until writing is complete or failure
int8_t block_write(int fd, void *data, size_t size);

#endif
