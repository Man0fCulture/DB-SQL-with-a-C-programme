#include "btree.h"
#include <string.h>


name_col_t *add_col(char *name, int16_t line)
{
    name_col_t *new_node = malloc(sizeof(name_col_t));
    int8_t i = 0;

    if (new_node == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    new_node->line = line;
    new_node->next = NULL;
    new_node->col = NULL;
    new_node->name = malloc(sizeof(char) * (strlen(name) + 1));

    for (; name[i] != 0; i++) {
        new_node->name[i] = name[i];
    }
    name[i] = 0;
    return new_node;
}
