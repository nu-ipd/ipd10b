#include "string_fun.h"
#include "heap_string.h"
#include "ptr_string.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Heap-allocates and returns a new string that is the concatenation of
// the given two strings.
char* string_concat(char const* s, char const* t)
{
    size_t s_len = strlen(s);
    size_t t_len = strlen(t);

    char* result = malloc(s_len + t_len + 1);
    if (!result) {
        return NULL;
    }

    strcpy(result, s);
    strcpy(result + s_len, t);

    return result;
}

// Checks whether a line of text is a C line comment.
bool is_comment(char const* s) {
    while (*s && isspace(*s)) {
        ++s;
    }

    return s[0] == '/' && s[1] == '/';
}

// Concatenates all non-comment lines, with newlines in between.
// In particular, assuming that `lines` is a pointer to an array of
// `count` C strings, allocates and returns a new string that is
// the concatenation of all strings that are not C line comments.
// The resulting string is heap allocated and must be freed by the
// caller.
//
// Errors: Returns NULL if it can't allocate memory.
char* strip_concat(char const* const lines[], size_t n)
{
    size_t total_len = 0;

    for (size_t i = 0; i < n; ++i) {
        if (! is_comment(lines[i])) {
            total_len += strlen(lines[i]) + 1; // 1 for '\n'
        }
    }

    char* const result = malloc(total_len + 1);
    if (! result) {
        return NULL;
    }

    char* fill = result;

    for (size_t i = 0; i < n; ++i) {
        if (is_comment(lines[i])) continue;
        strcpy(fill, lines[i]);
        fill += strlen(fill);
        *fill++ = '\n';
    }

    *fill = 0;

    return result;
}
