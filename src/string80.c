#include <ctype.h>
#include <stdio.h>

struct string80
{
    char data[81];
};

typedef struct string80 string80_t;

// Converts a string to uppercase by making a copy. The copy is stored
// in its stack frame and then copied back to the caller’s stack frame.
string80_t str_toupper_copy(string80_t s)
{
    for (size_t i = 0; s.data[i] != '\0'; ++i)
        s.data[i] = toupper(s.data[i]);

    return s;
}

// Converts a string to uppercase in place. The string is passed by
// pointer, so is not copied.
void str_toupper_ptr(string80_t* s)
{
    for (size_t i = 0; s->data[i] != '\0'; ++i)
        s->data[i] = toupper(s->data[i]);
}

// Example using str_toupper_copy:
void pass_copy(void)
{
    string80_t s1 = {"Uniform capacity, pass copy"};
    string80_t s2 = str_toupper_copy(s1);
    printf("%s\n", s1.data);
    printf("%s\n", s2.data);
}

// Example using str_toupper_ptr:
void pass_ptr(void)
{
    string80_t s1 = {"Uniform capacity, pass ptr"};
    printf("%s\n", s1.data);
    str_toupper_ptr(&s1);
    printf("%s\n", s1.data);
}

int main(void)
{
    pass_copy();
    pass_ptr();
}
