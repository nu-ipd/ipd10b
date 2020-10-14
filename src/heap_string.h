// See .c file for purpose statements.
#pragma once

// Allocates a new copy of the given string on the heap. The result must
// be freed. Returns NULL if it can't allocate memory.
char* string_clone(const char* s);

// Allocates a new, UPPERCASE copy of the given string on the heap. The
// result must be freed. Returns NULL if it can't allocate memory.
char* string_clone_toupper(const char* s);
