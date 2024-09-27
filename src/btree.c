#include "btree.h"
#include "define.h"
#include "search.c"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

static btree_t *add_node(char *data)
{
    btree_t *new_node = malloc(sizeof(btree_t));
    int8_t i = 0;

    if (new_node == NULL) {
        return NULL;
    }
    new_node->name_table = malloc(sizeof(char) * (strlen(data) + 1));
    for (; data[i] != 0; i++) {
        new_node->name_table[i] = data[i];
    }
    new_node->name_table[i] = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->curr = NULL;
    new_node->C = NULL;
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
            curr->stock = right_s;
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
            curr->stock = left_s;
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


int main(int ac, char **argv)
{
    btree_t *tree = NULL;

    create_node(&tree, "Test01");
    printf("%s\n", tree->name_table);
    create_node(&tree, "Test02");
    printf("%s\n", tree->left->name_table);
    create_node(&tree, "Test03");
    printf("%s\n", tree->right->name_table);
    create_node(&tree, "Test04");
    printf("%s\n", tree->left->left->name_table);
    create_node(&tree, "Test05");
    printf("%s\n", tree->right->left->name_table);
    btree_t *curr = search(tree, "Test02");

    printf("search = %s\n", curr->name_table);

    return SUCCES;
}