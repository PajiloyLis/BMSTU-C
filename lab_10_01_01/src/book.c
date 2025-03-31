#include "book.h"

int dynamic_string_read(char **str, ssize_t *n, FILE *f);

int book_read_from_file(book_t *book, FILE *f);

int book_compare(const void *a, const void *b)
{
    int author_comparison = strcmp(((book_t *)a)->author, ((book_t *)b)->author);
    if (!author_comparison)
    {
        return strcmp(((book_t *)a)->title, ((book_t *)b)->title);
    }
    return author_comparison;
}

int books_read_from_file(vector_t *books, char *file_name)
{
    int rc = EXIT_SUCCESS;
    books->elems_cnt = 0;
    FILE *f = fopen(file_name, "r");
    if (!f)
        return FILE_OPEN_ERROR;
    if ((rc = book_read_from_file((book_t *)((char *)books->array + books->elem_size * books->elems_cnt), f)) == EXIT_SUCCESS)
    {
        books->elems_cnt++;
        if (books->elems_cnt == books->allocated_cnt)
            rc = vector_reallocate(books);
        while (rc == EXIT_SUCCESS && (rc = book_read_from_file((book_t *)((char *)books->array + books->elem_size * books->elems_cnt), f)) == EXIT_SUCCESS)
        {
            books->elems_cnt++;
            if (books->elems_cnt == books->allocated_cnt)
                rc = vector_reallocate(books);
        }
        if (rc != YEAR_READING_ERROR)
            rc = feof(f) ? EXIT_SUCCESS : FILE_READING_ERROR;
    }
    else if (rc != YEAR_READING_ERROR)
        rc = feof(f) ? FILE_EMPTY_ERROR : FILE_READING_ERROR;
    fclose(f);
    return rc;
}

int book_read_from_file(book_t *book, FILE *f)
{
    if (!book || !f)
        return BOOK_READING_ERROR;
    int rc = EXIT_SUCCESS;
    book->title = book->author = NULL;
    book->title_len = book->author_len = 0;
    rc = dynamic_string_read(&(book->title), &(book->title_len), f);
    rc = rc == EXIT_SUCCESS ? dynamic_string_read(&(book->author), &(book->author_len), f) : rc;
    if (rc == EXIT_SUCCESS)
    {
        if (fscanf(f, "%hd\n", &(book->year)) == 1)
        {
            if (book->year == 0)
                rc = ZERO_YEAR_ERROR;
        }
        else
            rc = YEAR_READING_ERROR;
    }
    return rc;
}

void book_print(void *book)
{
    printf("%s\n%s\n%u\n", ((book_t *)book)->title, ((book_t *)book)->author, ((book_t *)book)->year);
}

int dynamic_string_read(char **str, ssize_t *n, FILE *f)
{
    int rc = EXIT_SUCCESS;
    *str = NULL;
    *n = 0;
    size_t mem = 0;
    rc = (*n = getline(str, &mem, f)) == -1 ? STRING_READING_ERROR : EXIT_SUCCESS;
    if (rc == EXIT_SUCCESS)
    {
        if (*n == 0)
            rc = EMPTY_STRING_ERROR;
        else if ((*str)[*n - 1] == '\n')
        {
            (*str)[--(*n)] = 0;
            if (*n == 0)
                rc = EMPTY_STRING_ERROR;
        }
    }
    if (rc != EXIT_SUCCESS)
        free(*str);
    return rc;
}