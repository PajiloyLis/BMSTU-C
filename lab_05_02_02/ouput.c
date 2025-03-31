#include "output.h"

void output(int code, double ans)
{
    switch (code)
    {
        case FILE_OPEN_ERROR:
            printf("Can not open file\n");
            break;
        case FILE_EMPTY_ERROR:
            printf("File is empty\n");
            break;
        case FILE_READING_ERROR:
            printf("File reading error\n");
            break;
        case EXIT_FAILURE:
            printf("Arguments count error\n");
            break;
        case EXIT_SUCCESS:
            printf("Answer is %.6lf\n", ans);
            break;
    }
}
