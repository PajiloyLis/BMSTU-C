#include "red_black_tree.h"

struct node_t
{
    void *data;
    bool is_red;
    node_t left, right, p;
};

static void left_rotate(node_t *root, node_t x);

static void right_rotate(node_t *root, node_t y);

static void transplant(node_t *root, node_t u, node_t v);

static void insert_repaint(node_t *root, node_t cur_node);

static void remove_repaint(node_t *root, node_t x);

node_t node_allocate(void *data)
{
    node_t node = calloc(1, sizeof(struct node_t));
    if (!node)
        return NULL;
    node->data = data;
    return node;
}

void *tree_get_data_by_node(node_t node)
{
    return node->data;
}

void tree_insert(node_t *root, node_t node_to_insert, int (*data_cmp)(void *, void *))
{
    node_t new_node_ancestor = NULL, buf = *root;
    while (buf != NULL)
    {
        new_node_ancestor = buf;
        if (data_cmp(node_to_insert->data, buf->data) < 0)
            buf = buf->left;
        else
            buf = buf->right;
    }
    node_to_insert->p = new_node_ancestor;
    if (new_node_ancestor == NULL)
        *root = node_to_insert;
    else if (data_cmp(node_to_insert->data, new_node_ancestor->data) < 0)
        new_node_ancestor->left = node_to_insert;
    else
        new_node_ancestor->right = node_to_insert;
    node_to_insert->is_red = true;
    insert_repaint(root, node_to_insert);
}

void tree_delete(node_t *root, node_t node_to_delete, void (*data_delete)(void *))
{
    node_t y = node_to_delete, x;
    bool y_real_is_red = y->is_red;
    if (!node_to_delete->left)
    {
        x = node_to_delete->right;
        transplant(root, node_to_delete, node_to_delete->right);
    }
    else if (!node_to_delete->right)
    {
        x = node_to_delete->left;
        transplant(root, node_to_delete, node_to_delete->left);
    }
    else
    {
        y = tree_min(node_to_delete->right);
        y_real_is_red = y->is_red;
        x = y->right;
        if (y->p == node_to_delete && x)
            x->p = y;
        else
        {
            transplant(root, y, y->right);
            y->right = node_to_delete->right;
            if (y->right)
                y->right->p = y;
        }
        transplant(root, node_to_delete, y);
        y->left = node_to_delete->left;
        y->left->p = y;
        y->is_red = node_to_delete->is_red;
    }
    if (!y_real_is_red)
    {
        remove_repaint(root, x);
    }
    data_delete(node_to_delete->data);
    free(node_to_delete);
}

node_t tree_search(node_t subtree_root, void *data_to_find, int (*data_cmp)(void *, void *))
{
    int comparison_result;
    while (subtree_root && (comparison_result = data_cmp(subtree_root->data, data_to_find)))
    {
        if (comparison_result > 0)
            subtree_root = subtree_root->left;
        else
            subtree_root = subtree_root->right;
    }
    return subtree_root;
}

void tree_clear(node_t subtree_root, void (*data_delete)(void *))
{
    if (subtree_root)
    {
        tree_clear(subtree_root->left, data_delete);
        tree_clear(subtree_root->right, data_delete);
        data_delete(subtree_root->data);
        free(subtree_root);
    }
}

void tree_each(node_t subtree_root, void (*action)(const char *key, int *num, void *param), void *param, char *(*get_key)(void *), int *(get_val)(void *))
{
    if (subtree_root)
    {
        tree_each(subtree_root->left, action, param, get_key, get_val);
        action(get_key(subtree_root->data), get_val(subtree_root->data), param);
        tree_each(subtree_root->right, action, param, get_key, get_val);
    }
}

node_t tree_min(node_t subtree_root)
{
    for (; subtree_root->left; subtree_root = subtree_root->left);
    return subtree_root;
}

node_t tree_max(node_t subtree_root)
{
    for (; subtree_root->right; subtree_root = subtree_root->right);
    return subtree_root;
}

static void insert_repaint(node_t *root, node_t cur_node)
{
    node_t uncle_node;
    while (cur_node->p && cur_node->p->is_red)
    {
        if (cur_node->p == cur_node->p->p->left)
        {
            uncle_node = cur_node->p->p->right;
            if (uncle_node && uncle_node->is_red)
            {
                cur_node->p->is_red = uncle_node->is_red = false;
                cur_node->p->p->is_red = true;
                cur_node = cur_node->p->p;
            }
            else
            {
                if (cur_node == cur_node->p->right)
                {
                    cur_node = cur_node->p;
                    if (cur_node->right)
                        left_rotate(root, cur_node);
                }
                cur_node->p->is_red = false;
                cur_node->p->p->is_red = true;
                if (cur_node->p->p->left)
                    right_rotate(root, cur_node->p->p);
            }
        }
        else
        {
            uncle_node = cur_node->p->p->left;
            if (uncle_node && uncle_node->is_red)
            {
                cur_node->p->is_red = uncle_node->is_red = false;
                cur_node->p->p->is_red = true;
                cur_node = cur_node->p->p;
            }
            else
            {
                if (cur_node == cur_node->p->left)
                {
                    cur_node = cur_node->p;
                    if (cur_node->left)
                        right_rotate(root, cur_node);
                }
                cur_node->p->is_red = false;
                cur_node->p->p->is_red = true;
                if (cur_node->p->p->right)
                    left_rotate(root, cur_node->p->p);
            }
        }
    }
    (*root)->is_red = false;
}

static void remove_repaint(node_t *root, node_t x)
{
    node_t x_bro;
    while (x && x != *root && !x->is_red)
    {
        if (x == x->p->left)
        {
            x_bro = x->p->right;
            if (x_bro && x_bro->is_red)
            {
                x_bro->is_red = false;
                x->p->is_red = true;
                left_rotate(root, x->p);
                x_bro = x->p->right;
            }
            if (x_bro && (!x_bro->right || !x_bro->right->is_red) && (!x_bro->left || !x_bro->left->is_red))
            {
                x_bro->is_red = true;
                x = x->p;
            }
            else
            {
                if (x_bro && (!x_bro->right || !x_bro->right->is_red))
                {
                    if (x_bro->left)
                        x_bro->left->is_red = false;
                    x_bro->is_red = true;
                    right_rotate(root, x_bro);
                    x_bro = x->p->right;
                }
                x_bro->is_red = x->p->is_red;
                x->p->is_red = false;
                left_rotate(root, x->p);
                x = *root;
            }
        }
        else
        {
            x_bro = x->p->left;
            if (x_bro && x_bro->is_red)
            {
                x_bro->is_red = false;
                x->p->is_red = true;
                right_rotate(root, x->p);
                x_bro = x->p->left;
            }
            if (x_bro && (!x_bro->right || !x_bro->right->is_red) && (!x_bro->left || !x_bro->left->is_red))
            {
                x_bro->is_red = true;
                x = x->p;
            }
            else
            {
                if (x_bro && (!x_bro->left || !x_bro->left->is_red))
                {
                    if (x_bro->right)
                        x_bro->right->is_red = false;
                    x_bro->is_red = true;
                    left_rotate(root, x_bro);
                    x_bro = x->p->left;
                }
                x_bro->is_red = x->p->is_red;
                x->p->is_red = false;
                right_rotate(root, x->p);
                x = *root;
            }
        }
    }
    if (x)
        x->is_red = false;
}

static void left_rotate(node_t *root, node_t l)
{
    node_t r = l->right;
    l->right = r->left;
    if (r->left)
        r->left->p = l;
    r->p = l->p;
    if (!l->p)
        *root = r;
    else if (l == l->p->left)
        l->p->left = r;
    else
        l->p->right = r;
    r->left = l;
    l->p = r;
}

static void right_rotate(node_t *root, node_t r)
{
    node_t l = r->left;
    r->left = l->right;
    if (l->right)
        l->right->p = r;
    l->p = r->p;
    if (!r->p)
        *root = l;
    else if (r == r->p->left)
        r->p->left = l;
    else
        r->p->right = l;
    l->right = r;
    r->p = l;
}

static void transplant(node_t *root, node_t u, node_t v)
{
    if (u->p == NULL)
        *root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    if (v)
        v->p = u->p;
}
