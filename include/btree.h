#ifndef BTREE_H_
    #define BTREE_H_

typedef struct btree_s
{
    struct btree_s *right;
    struct btree_s *left;
    struct btree_s *curr;
} btree_t;


#endif