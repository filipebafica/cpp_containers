// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
#define CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_

#include <cstddef>
#include <iostream>

namespace ft {
template<typename T>
struct node {
    char              color;
    T                 key;
    node              *parent;
    node              *left;
    node              *right;
};

template<typename T>
class red_black_tree {
 public:
    node<T> *root;

    red_black_tree(void);
    ~red_black_tree(void);

    void print_tree_debug(void);
    void print_tree_debug(node<T> *node);

    void insert(T key);

 private:
    node<T> *create_node(T key);
    void insert_fixup(node<T> *new_node);
    void left_rotate(node<T> *x);
    void right_rotate(node<T> *y);
};
}  // namespace ft

#include "./red_black_tree.tpp"

#endif  // CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
