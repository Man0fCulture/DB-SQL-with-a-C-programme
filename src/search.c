#include "btree.h"
#include "define.h"
#include <string.h>


btree_t *search(btree_t *tree, char *table_name)
{
    btree_t *curr = tree;
    btree_t *save = NULL;
    int8_t count = 0;

    if (curr == NULL) {
        return NULL;
    }

    while (count > 2) {
        if (strcmp(table_name, curr->name_table) == 0) {
            return curr;
        }
        save = search(curr, table_name);
        if (save != NULL) {
            return save;
        }
        count += 1;
    }
    return NULL;
}
