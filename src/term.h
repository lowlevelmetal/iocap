/*
 * iocap
 *
 * term.h
 * 03-14-2024
 */

#ifndef   __TERM_H_
#define  __TERM_H_

// Standard library
#include <stdint.h>

// Termios
#include <termios.h>

// Local includes
#include "macro.h"

// Macros
#define TERM_RAW 0

// Create/Destroy
void init_term();
void reset_term();

// Terminal Configuration
int8_t set_term_mode(uint8_t mode);

// Movement
int8_t move_term_cursor(uint16_t x, uint16_t y);
int8_t clear_term();

#endif
