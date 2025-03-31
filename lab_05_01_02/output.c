#include "output.h"

void output(int code, int ans)
{
    switch (code)
    {
        case FILE_OPEN_ERROR:
            printf("Can not open file\n");
            break;
        case EMPTY_FILE_ERROR:
            printf("No numbers before end of input\n");
            break;
        case EXIT_SUCCESS:
            printf("Answer is %d\n", ans);
            break;
    }
}
