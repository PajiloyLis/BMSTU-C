#include "task.h"

int process(FILE *f, int *num)
{
    int return_code = EXIT_SUCCESS;
    *num = 0;
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        int cnt = 0, p_max, max;
        if (fscanf(f, "%d", &p_max) == 1)
        {
            cnt++;
            *num = 1;
            while (fscanf(f, "%d", &max) == 1)
            {
                cnt++;
                if (max > p_max)
                {
                    *num = cnt;
                    p_max = max;
                }
            }
        }
        else
        {
            return_code = EMPTY_FILE_ERROR;
        }
    }
    return return_code;
}
