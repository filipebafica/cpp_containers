// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "./map.hpp"

template<MAP_TEMPLATE>
ft::map<MAP_TYPES>::value_compare::value_compare(Compare c) : comp(c) {}

template<MAP_TEMPLATE>
bool ft::map<MAP_TYPES>::value_compare::operator()(const value_type& x, const value_type& y) const {
    return (comp(x.first, y.first));
}

template<MAP_TEMPLATE>
ft::map<MAP_TYPES>::map(void) : memory_tree(Compare(), Alloc()) {}

template<MAP_TEMPLATE>
ft::map<MAP_TYPES>::map(iterator first,
                        iterator last,
                        const key_compare& comp,
                        const allocator_type& alloc
                    ) :
                        memory_tree(comp, alloc)
{
    this->memory_tree.insert_unique_rb_node(first, last);
}

/******************** MEMBER FUNCTIONS ********************/
// modifiers
template<MAP_TEMPLATE>
ft::pair<typename ft::map<MAP_TYPES>::iterator, bool> ft::map<MAP_TYPES>::insert(const value_type& value) {
    return (this->memory_tree.insert_unique_rb_node(value));
}