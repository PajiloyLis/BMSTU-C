#include "lab_04_01_02.h"

int main(void)
{
    printf("strpbrk tests failed: %d\n", test_strpbrk());
    printf("strspn tests failed: %d\n", test_strspn());
    printf("strcspn tests failed: %d\n", test_strcspn());
    printf("strchr tests failed: %d\n", test_strchr());
    printf("strrchr tests failed: %d\n", test_strrchr());
}
