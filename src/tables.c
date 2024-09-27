#include "btree.h"
#include <string.h>

static char *allocate_char(char *data)
{
    char *str = malloc(sizeof(char) * (strlen(data) + 1));
    int8_t i = 0;

    if (str == NULL) {
        printf("Error can't allocate memory for a string\n");
        return NULL;
    }

    for (; data[i] != 0; i++) {
        str[i] = data[i];
    }
    str[i] = 0;

    return str;
}

column_t *add_col(name_col_t *c, char *data)
{
    column_t *new_node = malloc(sizeof(column_t));
    name_col_t *curr_col = c;

    if (new_node == NULL) {
        printf("Error in malloc can't allocate memory for a new column element\n");
        return NULL;
    }
    new_node->next = NULL;
    new_node->data = allocate_char(data);

    if (c == NULL) {
        return new_node;
    }
}

name_col_t *add_column_line(char *name, int16_t line)
{
    name_col_t *new_node = malloc(sizeof(name_col_t));
    int8_t i = 0;

    if (new_node == NULL) {
        printf("Error in malloc can't allocate memory for a new column\n");
        return NULL;
    }
    new_node->line = line;
    new_node->next = NULL;
    new_node->col = NULL;
    new_node->name = allocate_char(name);

    return new_node;
}
