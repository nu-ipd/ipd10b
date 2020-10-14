#pragma once

#include <stdbool.h>

// Reads a line of input on stdin. The returned string is allocated by
// `malloc` and must be freed with `free`. Returns NULL on end-of-file
// or out-of-memory.
char* read_line(void);

// From <stdlib.h>, but necessary for using `read_line` correctly.
void free(void*);
