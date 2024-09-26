#ifndef BTREE_H_
    #define BTREE_H_

#include <stdlib.h>

enum where_to_stock{
    left_s = 0,
    right_s = 1
} where_to_stock;

typedef struct btree_s
{
    char *data;
    enum where_to_stock stock;
    struct btree_s *right;
    struct btree_s *left;
    struct btree_s *curr;
} btree_t;


#endif