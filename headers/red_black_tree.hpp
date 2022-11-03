// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
#define CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_

#include <cstddef>
#include <iostream>
#include <string>
#include <limits>
#include "./rb_iterator.hpp"
#include "./const_rb_iterator.hpp"
#include "./rb_reverse_iterator.hpp"
#include "./pair.hpp"

#define RB_TREE_TEMPLATE typename Key_type, \
                         typename Value_type, \
                         typename Key_compare, \
                         typename Alloc

#define RB_TREE_TYPES   Key_type, \
                        Value_type, \
                        Key_compare, \
                        Alloc

#define RB_NODE_TEMPLATE   typename Value_type

#define RB_NODE_TYPES Value_type

namespace ft {
template<typename Value_type>
struct rb_node {
    typedef Value_type   value_type;

    value_type           data;
    char                 color;
    rb_node              *parent;
    rb_node              *left;
    rb_node              *right;
    rb_node              *root;
    rb_node              *nil;
    explicit rb_node(void);
    explicit rb_node(ft::rb_node<RB_NODE_TYPES> *root);
    explicit rb_node(const value_type& data, ft::rb_node<RB_NODE_TYPES> *root, ft::rb_node<RB_NODE_TYPES> *nil);
};

template<typename Key_type, typename Value_type, typename Key_compare, typename Alloc>
class red_black_tree {
 public:
    /**************************************** MEMBER TYPES ****************************************/
    typedef typename Alloc::template rebind<ft::rb_node<RB_NODE_TYPES> >::other allocator_type;
    typedef typename allocator_type::pointer                                    pointer;
    typedef typename allocator_type::const_pointer                              const_pointer;
    typedef typename ft::rb_iterator<pointer, red_black_tree>                   iterator;
    typedef typename ft::const_rb_iterator<const_pointer, red_black_tree>       const_iterator;
    typedef typename ft::rb_reverse_iterator<iterator, red_black_tree>          reverse_iterator;
    typedef typename ft::rb_reverse_iterator<const_iterator, red_black_tree>    const_reverse_iterator;
    typedef ptrdiff_t                                                           difference_type;
    typedef size_t                                                              size_type;
    typedef Key_type                                                            key_type;
    typedef Value_type                                                          value_type;
    typedef Key_compare                                                         key_compare;

    /**************************************** MEMBER ATRIBUTES ****************************************/
    key_compare                                                                 key_comp;
    allocator_type                                                              rb_node_alloc;
    ft::rb_node<RB_NODE_TYPES>                                                  *root;
    ft::rb_node<RB_NODE_TYPES>                                                  *nil;
    size_type                                                                   node_count;

    /**************************************** CONSTRUCTORS / DESTRUCTORS ****************************************/
    red_black_tree(void);
    red_black_tree(const key_compare& key_comp = key_compare(), const allocator_type& rb_node_alloc = allocator_type());
    red_black_tree(const red_black_tree& src,
                   const key_compare& key_comp = key_compare(),
                   const allocator_type& rb_node_alloc = allocator_type());
    red_black_tree& operator=(const red_black_tree& rhs);
    ~red_black_tree(void);

    /**************************************** MEMBER FUNCTIONS ****************************************/
    iterator begin(void);
    const_iterator begin(void) const;
    iterator end(void);
    const_iterator end(void) const;
    bool empty(void) const;
    size_type size(void) const;
    size_type max_size(void) const;
    void clear(void);
    void erase(iterator position);
    void erase(iterator first, iterator last);
    size_type erase(const key_type& k);

    void print_tree_debug(void) const;
    ft::pair<iterator, bool> insert_unique_rb_node(const value_type& value);
    iterator insert_unique_rb_node(iterator hint, const value_type& value);
    void insert_unique_rb_node(iterator first, iterator last);
    void delete_rb_node(key_type key);

   ft::rb_node<RB_NODE_TYPES> *search_rb_node(key_type key);
   static ft::rb_node<RB_NODE_TYPES> *minimum_rb_node(ft::rb_node<RB_NODE_TYPES> *x);
   static ft::rb_node<RB_NODE_TYPES> *maximum_rb_node(ft::rb_node<RB_NODE_TYPES> *x);
   static ft::rb_node<RB_NODE_TYPES> *successor_rb_node(ft::rb_node<RB_NODE_TYPES> *x);
   static const ft::rb_node<RB_NODE_TYPES> *successor_rb_node(const ft::rb_node<RB_NODE_TYPES> *x);
   static ft::rb_node<RB_NODE_TYPES> *predecessor_rb_node(ft::rb_node<RB_NODE_TYPES> *x);
   static const ft::rb_node<RB_NODE_TYPES> *predecessor_rb_node(const ft::rb_node<RB_NODE_TYPES> *x);

 private:
    ft::rb_node<RB_NODE_TYPES> *create_rb_node(const value_type& value);
    ft::rb_node<RB_NODE_TYPES> *insert_rb_node(ft::rb_node<RB_NODE_TYPES> *hint_node, const value_type& value);
    void insert_rb_node_fixup(ft::rb_node<RB_NODE_TYPES> *z);
    void left_rotate(ft::rb_node<RB_NODE_TYPES> *x);
    void right_rotate(ft::rb_node<RB_NODE_TYPES> *x);
    void transplant_rb_node(ft::rb_node<RB_NODE_TYPES> *u, ft::rb_node<RB_NODE_TYPES> *v);
   ft::rb_node<RB_NODE_TYPES> *search_rb_node_aux(ft::rb_node<RB_NODE_TYPES> *x, key_type key);
    void print_tree_debug_aux(const ft::rb_node<RB_NODE_TYPES> *root, std::string indent, bool last) const;
    void inorder_print(const ft::rb_node<RB_NODE_TYPES> *node) const;
    void delete_rb_node_fixup(ft::rb_node<RB_NODE_TYPES> *x);
    void copy_aux(ft::rb_node<RB_NODE_TYPES> *x);
    void destructor_aux(ft::rb_node<RB_NODE_TYPES> *x);
};
}  // namespace ft

#include "./red_black_tree.tpp"

#endif  // CPP_CONTAINERS_HEADERS_RED_BACK_TREE_HPP_
