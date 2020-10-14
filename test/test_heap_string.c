#include "../src/heap_string.h"

#include <libipd.h>

#include <stdlib.h>
#include <string.h>

void test_string_clone_toupper(void)
{
    const char original[] = "Heap allocation!",
               expected[] = "HEAP ALLOCATION!";

    char* clone = string_clone_toupper(original);

    // `clone` might be NULL, but this is safe because CHECK_STRING
    // checks for NULL.
    CHECK_STRING( clone, expected );

    free(clone);
}

int main(void)
{
    test_string_clone_toupper();
}

