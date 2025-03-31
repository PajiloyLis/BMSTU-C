#include "test.h"
#define TEST_SIZE 5

int test_strpbrk(void)
{
    int diff = 0;
    const char *str[] = { "0123456789","abcdefesef",
        "asdfsdfsdf", "a a 1 2 3 2 3 4 1", "123", "" };
    const char *sym[] = { "693", "def", "a", "6 6", "abc", "\0" };
    for (int i = 0; i < TEST_SIZE; ++i)
    {
        if (my_strpbrk(*(str + i), *(sym + i)) != strpbrk(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strspn(void)
{
    int diff = 0;
    const char *str[] = { "0123456789", "abcdefesef",
        "asdfsdfsdf", "a a 1 2 3 2 3 4 1", "123" };
    const char *sym[] = { "0123", "adc", "a", "6 6", "1234" };
    for (int i = 0; i < TEST_SIZE; ++i)
    {
        if (my_strspn(*(str + i), *(sym + i)) != strspn(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strcspn(void)
{
    int diff = 0;
    const char *str[] = { "0123456789", "abcdefesef",
        "asdfsdfsdf", "a a 1 2 3 2 3 4 1", "123" };
    const char *sym[] = { "9", "", "e", "a", "1234" };
    for (int i = 0; i < TEST_SIZE; ++i)
    {
        if (my_strcspn(*(str + i), *(sym + i)) != strcspn(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strchr(void)
{
    int diff = 0;
    const char *str[] = { "0123456789", "abcdefesef",
        "asdfsdfsdfe", "a a 1 2 3 2 3 4 1", "123", "" };
    int sym[] = { (int)'5', (int)'a', (int)'e', (int)' ', (int)'a', (int)'\0' };
    for (int i = 0; i < TEST_SIZE; ++i)
    {
        if (my_strchr(*(str + i), *(sym + i)) != strchr(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strrchr(void)
{
    int diff = 0;
    const char *str[] = { "0123456789", "abcdefesef",
        "asdfsdfsdfe", "a a 1 2 3 2 3 4 1", "123", "a" };
    int sym[] = { (int)'5', (int)'f', (int)'e', (int)' ', (int)'f', (int)'\0' };
    for (int i = 0; i < TEST_SIZE; ++i)
    {
        if (my_strrchr(*(str + i), *(sym + i)) != strrchr(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}
