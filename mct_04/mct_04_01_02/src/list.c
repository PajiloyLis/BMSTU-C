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
node_t find_third_min(const node_t list)
{
    node_t min = list, second_min = NULL, third_min = NULL;
    for (node_t cur = list->next; cur; cur = cur->next)
    {
        if (cur->value <= min->value)
        {
            third_min = second_min;
            second_min = min;
            min = cur;
        }
        else if (!second_min || cur->value <= second_min->value)
        {
            third_min = second_min;
            second_min = cur;
        }
        else if (!third_min || cur->value <= third_min->value)
            third_min = cur;
    }
    return third_min;
}

node_t delete_node_by_pointer(node_t list, node_t to_del)
{
    node_t cur = list;
    if (cur == to_del)
    {
        list = list->next;
        free(to_del);
    }
    else
    {
        for (cur = list; cur->next != to_del; cur = cur->next)
            ;
        cur->next = cur->next->next;
        free(to_del);
    }
    return list;
}

void list_print(node_t list)
{
    for (; list; list = list->next)
        printf("%d ", list->value);
    printf("\n");
}