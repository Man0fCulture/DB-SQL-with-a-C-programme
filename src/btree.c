#include "btree.h"
#include "define.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

static btree_t *add_node(char *data)
{
    btree_t *new_node = malloc(sizeof(char) * strlen(data) + 1);
    int8_t i = 0;
    if (new_node == NULL) {
        return NULL;
    }
    for (; data[i] != 0; i++) {
        new_node->data[i] = data[i];
    }
    data[i] = 0;
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
                return ERROR;
            }
            return SUCCES;
        }
        if (find_to_stock(curr->left, data) == 84)
            return ERROR;
        curr->stock = right_s;
    } else {
        if (curr->right == NULL) {
            curr->right = add_node(data);
            if (curr->right == NULL) {
                return ERROR;
            }
            return SUCCES;
        }
        if (find_to_stock(curr->right, data) == 84)
            return ERROR;
        curr->stock = left_s;
    }
    return SUCCES;
}

int create_node(btree_t **tree, char *data)
{
    if ((*tree) == NULL) {
        (*tree) = add_node(data);
        return SUCCES;
    }
    btree_t *curr = (*tree);

    if (find_to_stock(curr, data) == ERROR) {
        printf("Error of malloc\n");
        return ERROR;
    }
    return SUCCES;
}