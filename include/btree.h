#ifndef BTREE_H_
    #define BTREE_H_

#include <stdlib.h>
#include <stdint.h>

enum where_to_stock{
    left_s = 0,
    right_s = 1
} where_to_stock;

typedef struct column_s {
    char *data;
    struct column_s *next;
} column_t;


typedef struct name_col_s {
    char *name;
    int16_t line;
    struct column_t *col;
    struct name_col_s *next;
} name_col_t;

typedef struct btree_s
{
    char *name_table;
    name_col_t *C;
    enum where_to_stock stock;
    struct btree_s *right;
    struct btree_s *left;
    struct btree_s *curr;
} btree_t;


#endif