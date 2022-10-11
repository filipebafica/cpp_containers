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
    ft::node<T> *root;

    red_black_tree(void);
    ~red_black_tree(void);

    void print_tree_debug(void);

    void insert_node(T key);
    void delete_node(T key);
    ft::node<T> *search_node(T key);
    ft::node<T> *minimum_node(ft::node<T> *x);
    ft::node<T> *maximum_node(ft::node<T> *x);

 private:
    ft::node<T> *create_node(T key);
    void insert_node_fixup(ft::node<T> *z);
    void left_rotate(ft::node<T> *x);
    void right_rotate(ft::node<T> *y);
    void transplant_node(ft::node<T> *u, ft::node<T> *v);
    ft::node<T> *search_node_aux(ft::node<T> *x, T key);
    void print_tree_debug_aux(ft::node<T> *node);
};
}  // namespace ft

#include "./red_black_tree.tpp"

#endif  // CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
