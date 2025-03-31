#include "file.h"

int swap(size_t i, int a, size_t j, int b, FILE *f);

int make_file(char *file_name, size_t n);

int read_file(char *file_name);

int insertion_sort(char *file_name);

int file_size(FILE *f, size_t *size);

int get_number_by_pos(size_t pos, FILE *f, type *val);

int put_number_by_pos(size_t pos, FILE *f, type val);

int solution(char *mode, char *file_name, size_t cnt)
{
    int return_code = EXIT_SUCCESS;
    if (!strcmp(mode, "c"))
    {
        return_code = make_file(file_name, cnt);
    }
    else if (!strcmp(mode, "p"))
    {
        return_code = read_file(file_name);
    }
    else
    {
        return_code = insertion_sort(file_name);
    }
    return return_code;
}

int make_file(char *file_name, size_t n)
{
    int return_code = EXIT_SUCCESS;
    FILE *f = fopen(file_name, "wb");
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        for (size_t i = 0; i < n && !return_code; ++i)
        {
            int val = rand() % 10;
            if (fwrite(&val, sizeof(type), 1, f) != 1)
            {
                return_code = FILE_WRITING_ERROR;
            }
        }
        fclose(f);
    }
    return return_code;
}

int read_file(char *file_name)
{
    int return_code = EXIT_SUCCESS;
    FILE *f = fopen(file_name, "rb");
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        type val;
        if (fread(&val, sizeof(type), 1, f) == 1)
        {
            output(val);
            while (fread(&val, sizeof(type), 1, f) == 1)
            {
                output(val);
            }
            return_code = (feof(f) ? EXIT_SUCCESS : FILE_READING_ERROR);
        }
        else
        {
            return_code = (feof(f) ? FILE_EMPTY_ERROR : FILE_READING_ERROR);
        }
        fclose(f);
    }
    return return_code;
}

int insertion_sort(char *file_name)
{
    int return_code = EXIT_SUCCESS;
    FILE *f;
    return_code = ((f = fopen(file_name, "rb+")) ? EXIT_SUCCESS : FILE_OPEN_ERROR);
    if (return_code == EXIT_SUCCESS)
    {
        size_t size = 0;
        return_code = file_size(f, &size);
        if (return_code == EXIT_SUCCESS)
        {
            size_t n = size / sizeof(type);
            for (size_t i = 1; i < n && !return_code; ++i)
            {
                int cur = 0, prev = 0;
                return_code = (get_number_by_pos(i, f, &cur) || get_number_by_pos(i - 1, f, &prev));
                if (return_code == EXIT_SUCCESS)
                {
                    for (size_t j = i; j > 0 && cur < prev && !return_code; --j)
                    {
                        return_code = (get_number_by_pos(j, f, &cur) || get_number_by_pos(j - 1, f, &prev));
                        if (return_code == EXIT_SUCCESS && cur < prev)
                        {
                            return_code = swap(j, cur, j - 1, prev, f);
                        }
                    }
                }
            }
        }
        fclose(f);
    }
    return return_code;
}

int file_size(FILE *f, size_t *size)
{
    int return_code = EXIT_SUCCESS;
    long val = 0;
    if (fseek(f, 0l, SEEK_END))
    {
        return_code = FILE_GET_SIZE_ERROR;
    }
    else
    {
        val = ftell(f);
        if (val < 0)
        {
            return_code = FILE_GET_SIZE_ERROR;
        }
        else
        {
            *size = val;
            return_code = (fseek(f, 0l, SEEK_SET) ? FILE_GET_SIZE_ERROR : EXIT_SUCCESS);
        }
    }
    return return_code;
}

int get_number_by_pos(size_t pos, FILE *f, type *val)
{
    int return_code = EXIT_SUCCESS;
    return_code = (fseek(f, (long)pos * sizeof(type), SEEK_SET) ? FILE_INDEX_ERROR : EXIT_SUCCESS);
    if (return_code == EXIT_SUCCESS)
    {
        type buf;
        if (fread(&buf, sizeof(type), 1, f) != 1)
        {
            return_code = (feof(f) ? FILE_INDEX_ERROR : FILE_READING_ERROR);
        }
        else
        {
            *val = buf;
        }
    }
    return return_code;
}

int put_number_by_pos(size_t pos, FILE *f, type val)
{
    int return_code = EXIT_SUCCESS;
    return_code = (fseek(f, (long)pos * sizeof(type), SEEK_SET) ? FILE_INDEX_ERROR : EXIT_SUCCESS);
    if (return_code == EXIT_SUCCESS && fwrite(&val, sizeof(type), 1, f) != 1)
    {
        return_code = FILE_WRITING_ERROR;
    }
    return return_code;
}

int swap(size_t i, int a, size_t j, int b, FILE *f)
{
    int return_code = EXIT_SUCCESS;
    return_code = (put_number_by_pos(i, f, b) | put_number_by_pos(j, f, a));
    return return_code;
}
