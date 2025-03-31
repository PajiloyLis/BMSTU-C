#include "list.h"

void front_back_split(node_t *head, node_t **back);

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

node_t *list_create_from_data(void *data, size_t size, size_t n)
{
    if (!size || !n || !data)
    {
        return NULL;
    }
    node_t *cur, *head = NULL, *tail = NULL;
    for (size_t i = 0; i < n; ++i)
    {
        cur = malloc(sizeof(node_t));
        if (!cur)
        {
            list_free(head);
            head = NULL;
        }
        else
        {
            cur->data = (void *)((char *)data + i * size);

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

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (!head || !*head || !elem)
        return;
    if (before == *head)
    {
        elem->next = *head;
        *head = elem;
    }
    else
    {
        node_t *cur = *head;
        while (cur->next && cur->next != before)
            cur = cur->next;
        if (cur->next == before)
        {
            elem->next = cur->next;
            cur->next = elem;
        }
    }
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    if (!head || !data || !comparator)
        return NULL;
    while (head && comparator(head->data, data))
        head = head->next;
    return head;
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (!head || !*head || !comparator)
        return;
    node_t *segment_start = *head, *cur_segment_end = (*head)->next, *buf;
    while (cur_segment_end)
    {
        if (!comparator(cur_segment_end->data, segment_start->data))
        {
            buf = cur_segment_end;
            cur_segment_end = cur_segment_end->next;
            free(buf);
        }
        else
        {
            segment_start->next = cur_segment_end;
            segment_start = cur_segment_end;
            cur_segment_end = cur_segment_end->next;
        }
    }
    if (segment_start->next)
        segment_start->next = NULL;
}

void front_back_split(node_t *head, node_t **back)
{
    if (!head || !back)
        return;
    *back = NULL;
    size_t cnt;
    node_t *head_copy = head;
    for (cnt = 0; head; head = head->next, cnt++);
    *back = head_copy;
    node_t *cur;
    for (size_t i = 0; i < cnt / 2 + cnt % 2; ++i)
    {
        cur = *back;
        *back = (*back)->next;
    }
    cur->next = NULL;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (!head_a || !head_b || !comparator)
        return NULL;
    node_t *head = NULL, *tail = NULL, *cur;
    while (*head_a && *head_b)
    {
        if (comparator((*head_a)->data, (*head_b)->data) < 0)
        {
            cur = *head_a;
            *head_a = (*head_a)->next;
        }
        else
        {
            cur = *head_b;
            *head_b = (*head_b)->next;
        }
        if (!head)
            head = cur;
        if (tail)
            tail->next = cur;
        tail = cur;
    }
    while (*head_a)
    {
        if (!head)
            head = *head_a;
        if (tail)
            tail->next = *head_a;
        tail = *head_a;
        *head_a = (*head_a)->next;
    }
    while (*head_b)
    {
        if (!head)
            head = *head_b;
        if (tail)
            tail->next = *head_b;
        tail = *head_b;
        *head_b = (*head_b)->next;
    }
    return head;
}

node_t *sort(node_t *list, int (*comparator)(const void *, const void *))
{
    if (!list || !list->data)
        return NULL;
    if (!list->next)
        return list;
    node_t *left = list, *right = list;
    front_back_split(left, &right);
    left = sort(left, comparator);
    right = sort(right, comparator);
    return sorted_merge(&left, &right, comparator);
}

void list_data_print(node_t *head, void (*printer)(void*))
{
    for (; head; head = head->next)
        printer(head->data);
}

void list_free(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
