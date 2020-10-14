#include <libipd.h>
#include <ctype.h>

// Returns a string that is like `s`, but any uppercase letters doubled.
//
// Examples:
//  - double_upper("hello")        => "hello"
//  - double_upper("Hello")        => "HHello"
//  - double_upper("IPD")          => "IIPPDD"
//  - double_upper("Evanston, IL") => "EEvanston, IILL"
//
char* double_upper(const char* s)
{
    // TODO: This function should only return NULL if it cannot allocate
    // memory. Fix it!
    return NULL;
}

void test_double_upper(void)
{
    // TODO: You probably want to write some stuff here, yeah?
}


int main(void)
{
    test_double_upper();
}
