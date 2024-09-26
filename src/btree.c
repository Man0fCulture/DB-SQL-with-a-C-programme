#include "btree.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static btree_t *add_node(char *data)
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

static int find_to_stock(btree_t *curr, char *data)
{
    if (curr->stock == left_s) {
        if (curr->left == NULL) {
            curr->left = add_node(data);
            if (curr->left == NULL) {
                return 84;
            }
            return 0;
        }
        find_to_stock(curr->left, data);
    } else {
        if (curr->right == NULL) {
            curr->right = add_node(data);
            if (curr->right == NULL) {
                return 84;
            }
            return 0;
        }
        find_to_stock(curr->right, data);
    }
    return 0;
}

int create_node(btree_t **tree, char *data)
{
    if ((*tree) == NULL) {
        (*tree) = add_node(data);
        return 0;
    }
    btree_t *curr = (*tree);

    if (find_to_stock(curr, data) == 84) {

    }
    
    return 0;
}