#include "list.h"
#include "book.h"
#include "args.h"
#include "vector.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    int ec = EXIT_SUCCESS;
    char *input_file = NULL, mode = 0;
    book_t buf_1, buf_2;
    vector_t books;
    ec = vector_allocate(&books, sizeof(book_t), VECTOR_DEFAULT_SIZE);
    ec = ec == EXIT_SUCCESS ? args_hadler(argc, argv, &input_file, &mode, &buf_1, &buf_2) : ec;
    ec = ec == EXIT_SUCCESS ? books_read_from_file(&books, input_file) : ec;
    node_t *list_of_books = NULL;
    node_t *buf, *elem = NULL;
    if (ec == EXIT_SUCCESS)
    {
        list_of_books = list_create_from_data(books.array, books.elem_size, books.elems_cnt);
        if (!list_of_books)
            ec = LIST_CREATION_ERROR;
    }
    if (ec == EXIT_SUCCESS)
    {
        switch (mode)
        {
            case INSERT:
                buf = find(list_of_books, &buf_2, book_compare);
                elem = list_create_from_data(&buf_1, sizeof(book_t), 1);
                if (!elem)
                    ec = LIST_CREATION_ERROR;
                else
                    insert(&list_of_books, elem, buf);
                list_data_print(list_of_books, book_print);
                break;
            case FIND:
                buf = find(list_of_books, &buf_1, book_compare);
                if (buf)
                    book_print((book_t *)buf->data);
                else
                    printf("Not found\n");
                break;
            case UNIQUE:
                remove_duplicates(&list_of_books, book_compare);
                list_data_print(list_of_books, book_print);
                break;
            case SORT:
                list_of_books = sort(list_of_books, book_compare);
                list_data_print(list_of_books, book_print);
                break;
        }
    }
    if (books.is_alocated)
    {
        for (size_t i = 0; i < books.elems_cnt; ++i)
        {
            book_t *book = (book_t *)((char *)books.array + books.elem_size * i);
            free(book->title);
            free(book->author);
        }
        vector_free(&books);
    }
    if (list_of_books)
        list_free(list_of_books);
}