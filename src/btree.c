#include "btree.h"
#include <stdlib.h>
#include <string.h>

btree_t *create_node(char *data)
{
    btree_t *new_node = malloc(sizeof(char) * strlen(data) + 1);

    if (new_node == NULL) {
        return NULL;
    }

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->curr = NULL;
    new_node->stock = left_s;

    return new_node;
}

