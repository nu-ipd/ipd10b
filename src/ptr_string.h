// See .c file for purpose statements.
#pragma once

// For size_t:
#include <stddef.h>

// This is strlen(3) from <string.h>.
size_t our_strlen(const char* s);

// Copies from 0-terminated C string src to dst, but UB if dst
// has insufficient capacity.
void our_strcpy(char* dst, const char* src);

// Converts a string to uppercase in place.
void string_toupper_inplace(char* s);

// Converts a string to uppercase while putting the result in
// a different buffer.
void strcpy_toupper(char* dst, const char* src);
