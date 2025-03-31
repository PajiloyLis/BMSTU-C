#include "list.h"

struct node_t
{
    int value;
    node_t next;
};

node_t list_create_from_array(int *array, size_t n)
{
    node_t cur = NULL, head = NULL, tail = NULL;
    for (int i = 0; i < n; ++i)
    {
        cur = calloc(1, sizeof(struct node_t));
        if (!cur)
        {
            list_free(head);
            head = NULL;
            break;
        }
        else
        {
            cur->value = array[i];
            cur->next = NULL;
            if (tail)
                tail->next = cur;
            tail = cur;
            if (!head)
                head = cur;
        }
    }
    return head;
}

void list_free(node_t list)
{
    for (node_t next = NULL; list; list = next)
    {
        next = list->next;
        free(list);
    }
}

// if not found - NULL, else pointer to third min
node_t list_find_max(const node_t list)
{
    node_t max = list;
    for (node_t cur = list->next; cur; cur = cur->next)
    {
        if (cur->value > max->value)
            max = cur;
    }
    return max;
}

void list_swap_values_by_pointers(node_t a, node_t b)
{
    if (a != b)
    {
        a->value = a->value ^ b->value;
        b->value = a->value ^ b->value;
        a->value = a->value ^ b->value;
    }
}

void list_print(node_t list)
{
    for (; list; list = list->next)
        printf("%d ", list->value);
    printf("\n");
}

node_t node_get_next(node_t node)
{
    return node->next;
}