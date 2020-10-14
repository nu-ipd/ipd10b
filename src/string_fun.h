// See .c file for purpose statements.
#pragma once

#include <stddef.h>

// Heap-allocates and returns a new string that is the concatenation of
// the given two strings.
char* string_concat(const char* s, const char* t);

// Concatenates all non-comment lines, with newlines in between.
// In particular, assuming that `lines` is a pointer to an array of
// `count` C strings, allocates and returns a new string that is
// the concatenation of all strings that are not C line comments.
// The resulting string is heap allocated and must be freed by the
// caller.
//
// Errors: Returns NULL if it can't allocate memory.
char* strip_concat(char const* const lines[], size_t count);
