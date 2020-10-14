#include "../src/string_fun.h"

#include <libipd.h>

#include <stdlib.h>
#include <string.h>

static void test_string_concat(void)
{
    char* s1 = string_concat("hello,", " IPD");
    CHECK_STRING( s1, "hello, IPD" );

    char* s2 = string_concat(s1, " students!");
    CHECK_STRING( s2, "hello, IPD students!" );

    free(s1);
    free(s2);
}

static void test_strip_concat(void)
{
    char const* const input[] = {
        "// the simplest C program",
        "int main(void)",
        "{",
        "    // optional:",
        "    return 0;",
        "}"
    };

    const char* expected = "int main(void)\n{\n    return 0;\n}\n";

    const size_t n = sizeof input / sizeof input[0];
    char* actual   = strip_concat(input, n);

    CHECK_STRING( actual, expected );

    free(actual);
}

int main(void)
{
    test_string_concat();
    test_strip_concat();
}
