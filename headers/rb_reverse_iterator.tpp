// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./rb_reverse_iterator.hpp"

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container>::rb_reverse_iterator() : memory_current(Iterator()) {
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container>::rb_reverse_iterator(const Iterator& i) : memory_current(Iterator(i)) {
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container>::rb_reverse_iterator(const rb_reverse_iterator& src) : memory_current(Iterator()) {
    *this = src;
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container>& ft::rb_reverse_iterator<Iterator, Container>::operator=(const rb_reverse_iterator& src) {
    this->memory_current = src.base();
    return (*this);
}

template<typename Iterator, typename Container>
typename ft::rb_reverse_iterator<Iterator, Container>::reference ft::rb_reverse_iterator<Iterator, Container>::operator*(void) const {
    return (this->memory_current->data);
}

template<typename Iterator, typename Container>
typename ft::rb_reverse_iterator<Iterator, Container>::pointer ft::rb_reverse_iterator<Iterator, Container>::operator->(void) const {
    return (&(this->memory_current->data));
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container>& ft::rb_reverse_iterator<Iterator, Container>::operator++(void) {
    this->memory_current = ft::red_black_tree<
                                    typename Container::key_type,
                                    typename Container::value_type,
                                    typename Container::key_compare,
                                    typename Container::allocator_type
                                >::predecessor_rb_node(this->memory_current);
    return (*this);
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container> ft::rb_reverse_iterator<Iterator, Container>::operator++(int) {
    rb_reverse_iterator old_iterator = *this;
    this->memory_current = ft::red_black_tree<
                                    typename Container::key_type,
                                    typename Container::value_type,
                                    typename Container::key_compare,
                                    typename Container::allocator_type
                                >::predecessor_rb_node(this->memory_current);
    return (old_iterator);
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container>& ft::rb_reverse_iterator<Iterator, Container>::operator--(void) {
    this->memory_current = ft::red_black_tree<
                                    typename Container::key_type,
                                    typename Container::value_type,
                                    typename Container::key_compare,
                                    typename Container::allocator_type
                                >::sucessor_rb_node(this->memory_current);
    return (*this);
}

template<typename Iterator, typename Container>
ft::rb_reverse_iterator<Iterator, Container> ft::rb_reverse_iterator<Iterator, Container>::operator--(int) {
    rb_reverse_iterator old_iterator = *this;
    this->memory_current = ft::red_black_tree<
                                    typename Container::key_type,
                                    typename Container::value_type,
                                    typename Container::key_compare,
                                    typename Container::allocator_type
                                >::sucessor_rb_node(this->memory_current);
    return (old_iterator);
}

template<typename Iterator, typename Container>
const Iterator& ft::rb_reverse_iterator<Iterator, Container>::base(void) const {
    return (this->memory_current);
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator==(
    const ft::rb_reverse_iterator<IteratorL, Container>& lhs,
    const ft::rb_reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator==(
    const ft::rb_reverse_iterator<Iterator, Container>& lhs,
    const ft::rb_reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator!=(
    const ft::rb_reverse_iterator<IteratorL, Container>& lhs,
    const ft::rb_reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator!=(
    const ft::rb_reverse_iterator<Iterator, Container>& lhs,
    const ft::rb_reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() != rhs.base());
}

