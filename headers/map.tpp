// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "./map.hpp"

/******************** CONSTRUCTORS ********************/
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

template<MAP_TEMPLATE>
ft::map<MAP_TYPES>::map(const map& src) : memory_tree(src.memory_tree) {}

template<MAP_TEMPLATE>
ft::map<MAP_TYPES>& ft::map<MAP_TYPES>::operator=(const map& rhs){
    this->memory_tree = rhs.memory_tree;
    return (*this);
}

/******************** CONSTRUCTORS ********************/
template<MAP_TEMPLATE>
ft::map<MAP_TYPES>::~map(void) {}

/******************** MEMBER FUNCTIONS ********************/
template<MAP_TEMPLATE>
ft::map<MAP_TYPES>::value_compare::value_compare(Compare c) : comp(c) {}

template<MAP_TEMPLATE>
bool ft::map<MAP_TYPES>::value_compare::operator()(const value_type& x, const value_type& y) const {
    return (comp(x.first, y.first));
}

// element access
template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::mapped_type& ft::map<MAP_TYPES>::operator[](const key_type& k) {
    // try to insert k
    // if k is already in, a pair that points to it will be returnd
    // if not, k will be insert with its default value type and returned
    ft::pair<iterator, bool> p = this->insert(ft::pair<key_type, mapped_type>(k, mapped_type()));
    return ((*p.first).second);
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::mapped_type& ft::map<MAP_TYPES>::at(const key_type& k) {
    if (this->memory_tree.search_rb_node(k) == NULL || this->memory_tree.search_rb_node(k) == this->memory_tree.nil)
        throw std::out_of_range("map::at");
    return ((*this)[k]);
}

template<MAP_TEMPLATE>
const typename ft::map<MAP_TYPES>::mapped_type& ft::map<MAP_TYPES>::at(const key_type& k) const {
    if (this->memory_tree.search_rb_node(k) == NULL || this->memory_tree.search_rb_node(k) == this->memory_tree.nil)
        throw std::out_of_range("map::at");
    return ((*this)[k]);
}

// iterators
template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::iterator ft::map<MAP_TYPES>::begin(void) {
    return (this->memory_tree.begin());
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_iterator ft::map<MAP_TYPES>::begin(void) const {
    return (this->memory_tree.begin());
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::iterator ft::map<MAP_TYPES>::end(void) {
    return (this->memory_tree.end());
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_iterator ft::map<MAP_TYPES>::end(void) const {
    return (this->memory_tree.end());
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::reverse_iterator ft::map<MAP_TYPES>::rbegin(void) {
    return (reverse_iterator(this->end()));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_reverse_iterator ft::map<MAP_TYPES>::rbegin(void) const {
    return (const_reverse_iterator(this->end()));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::reverse_iterator ft::map<MAP_TYPES>::rend(void) {
    return (reverse_iterator(this->begin()));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_reverse_iterator ft::map<MAP_TYPES>::rend(void) const {
    return (const_reverse_iterator(this->begin()));
}

// capacity
template<MAP_TEMPLATE>
bool ft::map<MAP_TYPES>::empty(void) const {
    return (this->memory_tree.empty());
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::size_type ft::map<MAP_TYPES>::size(void) const {
    return (this->memory_tree.size());
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::size_type ft::map<MAP_TYPES>::max_size(void) const {
    return (this->memory_tree.max_size());
}

// modifiers
template<MAP_TEMPLATE>
void ft::map<MAP_TYPES>::clear(void) {
    this->memory_tree.clear();
}

template<MAP_TEMPLATE>
ft::pair<typename ft::map<MAP_TYPES>::iterator, bool> ft::map<MAP_TYPES>::insert(const value_type& value) {
    return (this->memory_tree.insert_unique_rb_node(value));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::iterator ft::map<MAP_TYPES>::insert(iterator position, const value_type& value) {
    return (this->memory_tree.insert_unique_rb_node(position, value));
}

template<MAP_TEMPLATE>
void ft::map<MAP_TYPES>::insert(iterator first, iterator last) {
    return (this->memory_tree.insert_unique_rb_node(first, last));
}

template<MAP_TEMPLATE>
void ft::map<MAP_TYPES>::erase(iterator position) {
    this->memory_tree.erase(position);
}

template<MAP_TEMPLATE>
void ft::map<MAP_TYPES>::erase(iterator first, iterator last) {
    this->memory_tree.erase(first, last);
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::size_type ft::map<MAP_TYPES>::erase(const key_type& k) {
    return(this->memory_tree.erase(k));
}

template<MAP_TEMPLATE>
void ft::map<MAP_TYPES>::swap(map& x) {
    this->memory_tree.swap(x.memory_tree);
}

// operations
template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::iterator ft::map<MAP_TYPES>::find(const key_type& k) {
    return (this->memory_tree.find(k));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_iterator ft::map<MAP_TYPES>::find(const key_type& k) const {
    return (this->memory_tree.find(k));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::size_type ft::map<MAP_TYPES>::count(const key_type& k) const {
    return (this->memory_tree.count(k));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::iterator ft::map<MAP_TYPES>::lower_bound(const key_type& k) {
    return (this->memory_tree.lower_bound(k));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_iterator ft::map<MAP_TYPES>::lower_bound(const key_type& k) const {
    return (this->memory_tree.lower_bound(k));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::iterator ft::map<MAP_TYPES>::upper_bound(const key_type& k) {
    return (this->memory_tree.upper_bound(k));
}

template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::const_iterator ft::map<MAP_TYPES>::upper_bound(const key_type& k) const {
    return (this->memory_tree.upper_bound(k));
}


template<MAP_TEMPLATE>
ft::pair<typename ft::map<MAP_TYPES>::iterator, 
         typename ft::map<MAP_TYPES>::iterator> ft::map<MAP_TYPES>::equal_range(const key_type& k)
{
    return (this->memory_tree.equal_range(k));
}


template<MAP_TEMPLATE>
ft::pair<typename ft::map<MAP_TYPES>::const_iterator, 
         typename ft::map<MAP_TYPES>::const_iterator> ft::map<MAP_TYPES>::equal_range(const key_type& k) const
{
    return (this->memory_tree.equal_range(k));
}

// allocator
template<MAP_TEMPLATE>
typename ft::map<MAP_TYPES>::allocator_type ft::map<MAP_TYPES>::get_allocator(void) const {
    return (allocator_type());
}
