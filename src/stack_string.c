#include "ptr_string.h"
#include <stdio.h>

// This is can never work; if the caller uses the result at all, the
// behavior is undefined!
static char* bad_string_clone_toupper(const char* s)
{
    char buf[our_strlen(s) + 1];
    strcpy_toupper(buf, s);
    return buf;
}

int main(void)
{
    const char message[] = "Fixed size, pass ptr";
    char buf[sizeof message];
    our_strcpy(buf, message);

    printf("%s\n", buf);
    string_toupper_inplace(buf);
    printf("%s\n", buf);

    // The code that causes UB starts here:
    char* bad1 = bad_string_clone_toupper("one");
    char* bad2 = bad_string_clone_toupper("two");
    char* bad3 = bad_string_clone_toupper("three");

    printf("%s\n", bad1);
    printf("%s\n", bad2);
    printf("%s\n", bad3);
}
