// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
#define CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_

#include <cstddef>
#include <iostream>
#include <string>

#define RB_TREE_TEMPLATE typename Key_type, \
                         typename Value_type, \
                         typename Key_compare, \
                         typename Alloc

#define RB_TREE_TYPES   Key_type, \
                        Value_type, \
                        Key_compare, \
                        Alloc

#define NODE_TYPES Key_type

namespace ft {
template<typename T>
struct node {
    char              color;
    T                 pair;
    node              *parent;
    node              *left;
    node              *right;
};

template<typename Key_type, typename Value_type, typename Key_compare, typename Alloc>
class red_black_tree {
 public:
    /******************** MEMBER TYPES ********************/
    typedef typename Alloc::template rebind<ft::node<NODE_TYPES> >::other  allocator_type;
    typedef typename allocator_type::pointer                             pointer;
    typedef typename allocator_type::const_pointer                       const_pointer;
    // typedef typename ft::rb_iterator<pointer, red_black_tree>         iterator;
    // typedef typename ft::rb_iterator<const_pointer, red_black_tree>   const_iterator;
    // typedef typename ft::rb_reverse_iterator<iterator>                reverse_iterator;
    // typedef typename ft::rb_reverse_iterator<const_iterator>          const_reverse_iterator;
    typedef ptrdiff_t                                                    difference_type;
    typedef size_t                                                       size_type;
    typedef Key_type                                                     key_type;
    typedef Value_type                                                   value_type;
    typedef Key_compare                                                  key_compare;



    /******************** MEMBER ATRIBUTES ********************/
    key_compare                                              key_comp;
    allocator_type                                           node_alloc;
    ft::node<NODE_TYPES>                                     *root;
    ft::node<NODE_TYPES>                                     *nil;

    /******************** CONSTRUCTORS / DESTRUCTORS ********************/
    red_black_tree(void);
    red_black_tree(const key_compare& key_comp, const allocator_type& node_alloc);
    ~red_black_tree(void);

    /******************** MEMBER FUNCTIONS ********************/
    void print_tree_debug(void);
    void print_sorted_tree_debug(void);
    void insert_node(key_type key);
    void delete_node(key_type key);
    ft::node<NODE_TYPES> *search_node(key_type key);
    ft::node<NODE_TYPES> *minimum_node(ft::node<NODE_TYPES> *x);
    ft::node<NODE_TYPES> *maximum_node(ft::node<NODE_TYPES> *x);
    ft::node<NODE_TYPES> *successor_node(ft::node<NODE_TYPES> *x);
    ft::node<NODE_TYPES> *predecessor_node(ft::node<NODE_TYPES> *x);

 private:
    ft::node<NODE_TYPES> *create_node(key_type key);
    void insert_node_fixup(ft::node<NODE_TYPES> *z);
    void left_rotate(ft::node<NODE_TYPES> *x);
    void right_rotate(ft::node<NODE_TYPES> *x);
    void transplant_node(ft::node<NODE_TYPES> *u, ft::node<NODE_TYPES> *v);
    ft::node<NODE_TYPES> *search_node_aux(ft::node<NODE_TYPES> *x, key_type key);
    void print_tree_debug_aux(ft::node<NODE_TYPES> *root, std::string indent, bool last);
    void print_sorted_tree_debug_aux(ft::node<NODE_TYPES> *node);
    void delete_node_fixup(ft::node<NODE_TYPES> *x);

};
}  // namespace ft

#include "./red_black_tree.tpp"

#endif  // CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
