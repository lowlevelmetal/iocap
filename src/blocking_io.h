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
int8_t block_write(const int fd, const void * const data, const size_t size);

#endif
