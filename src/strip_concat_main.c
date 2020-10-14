#include "string_fun.h"
#include "read_line.h"

#include <stdio.h>

#define MAX_LINES 10

size_t read_lines(char* lines[], size_t capacity)
{
    size_t i = 0;

    while (i < capacity && (lines[i] = read_line()) != NULL) {
        ++i;
    }

    return i;
}

void free_lines(char* lines[], size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        free(lines[i]);
    }
}

int main(void)
{
    char* lines[MAX_LINES];

    size_t count = read_lines(lines, MAX_LINES);

    char* everything = strip_concat((const char* const*) lines, count);
    printf("%s", everything);

    free(everything);
    free_lines(lines, count);
}
