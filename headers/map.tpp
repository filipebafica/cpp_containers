// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "./map.hpp"

template<typename Key, typename T, typename Compare, typename Alloc>
ft::map<Key, T, Compare, Alloc>::value_compare::value_compare(Compare c) : comp(c) {}

template<typename Key, typename T, typename Compare, typename Alloc>
bool ft::map<Key, T, Compare, Alloc>::value_compare::operator()(const value_type& x, const value_type& y) const {
    return (comp(x.first, y.first));
}

template<typename Key, typename T, typename Compare, typename Alloc>
ft::map<Key, T, Compare, Alloc>::map(void) : memory_tree(Compare(), Alloc()) {}
