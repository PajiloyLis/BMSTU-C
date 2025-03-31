#include "args.h"

int atoh(char *str, short *n);

int args_hadler(int argc, char **argv, char **input_file, char *mode, book_t *buf_1, book_t *buf_2)
{
    if (!argv)
        return ARGS_NULL_POINTER_ERROR;
    if (argc < MODE_NUMBER + 1)
        return ARGS_COUNT_ERROR;
    if (argv[MODE_NUMBER][0] == '-')
    {
        switch (argv[MODE_NUMBER][1])
        {
            case FIND:
                if (argc < FIND_ARGS_COUNT)
                    return ARGS_COUNT_ERROR;
                if (atoh(argv[YEAR_NUMBER], &(buf_1->year)) != EXIT_SUCCESS)
                    return YEAR_CONVERTING_ERROR;
                *input_file = argv[INPUT_FILE_NUMBER];
                *mode = FIND;
                buf_1->title = argv[TITLE_NUMBER];
                buf_1->title_len = strlen(buf_1->title);
                buf_1->author = argv[AUTHOR_NUMBER];
                buf_1->author_len = strlen(buf_1->author);
                break;
            case INSERT:
                if (argc < INSERT_ARGS_COUNT)
                    return ARGS_COUNT_ERROR;
                if (atoh(argv[YEAR_NUMBER], &(buf_1->year)) != EXIT_SUCCESS)
                    return YEAR_CONVERTING_ERROR;
                if (atoh(argv[YEAR_2_NUMBER], &(buf_2->year)) != EXIT_SUCCESS)
                    return YEAR_CONVERTING_ERROR;
                *input_file = argv[INPUT_FILE_NUMBER];
                *mode = INSERT;
                buf_1->title = argv[TITLE_NUMBER];
                buf_1->title_len = strlen(buf_1->title);
                buf_1->author = argv[AUTHOR_NUMBER];
                buf_1->author_len = strlen(buf_1->author);
                buf_2->title = argv[TITLE_2_NUMBER];
                buf_2->title_len = strlen(buf_2->title);
                buf_2->author = argv[AUTHOR_2_NUMBER];
                buf_2->author_len = strlen(buf_2->author);
                break;
            case UNIQUE:
                if (argc < UNIQUE_ARGS_COUNT)
                    return ARGS_COUNT_ERROR;
                *input_file = argv[INPUT_FILE_NUMBER];
                *mode = UNIQUE;
                break;
            case SORT:
                if (argc < SORT_ARGS_COUNT)
                    return ARGS_COUNT_ERROR;
                *input_file = argv[INPUT_FILE_NUMBER];
                *mode = SORT;
                break;
            default:
                return OPERATION_KEY_ERROR;
                break;
        }
    }
    else
        return OPERATION_KEY_ERROR;
    return EXIT_SUCCESS;
}

int atoh(char *str, short *n)
{
    char *end;
    errno = 0;
    long buf = strtol(str, &end, BASE);
    int range_error = errno == ERANGE;
    if (range_error || *end)
        return YEAR_CONVERTING_ERROR;
    else if (buf > SHRT_MAX || buf < SHRT_MIN)
        return YEAR_CONVERTING_ERROR;
    *n = buf;
    return EXIT_SUCCESS;
}