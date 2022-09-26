// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./normal_iterator.hpp"

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>::normal_iterator() : memory_current(Iterator()) {
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>::normal_iterator(const Iterator& i) : memory_current(Iterator(i)) {
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>::normal_iterator(const normal_iterator& src) : memory_current(Iterator()) {
    *this = src;
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>& ft::normal_iterator<Iterator, Container>::operator=(const normal_iterator& src) {
    this->memory_current = src.base();
    return (*this);
}

template<typename Iterator, typename Container>
typename ft::normal_iterator<Iterator, Container>::reference ft::normal_iterator<Iterator, Container>::operator*(void) const {
    return (*this->memory_current);
}

template<typename Iterator, typename Container>
typename ft::normal_iterator<Iterator, Container>::pointer ft::normal_iterator<Iterator, Container>::operator->(void) const {
    return (this->memory_current);
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>& ft::normal_iterator<Iterator, Container>::operator++(void) {
    ++this->memory_current;
    return (*this);
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container> ft::normal_iterator<Iterator, Container>::operator++(int) {
    return (ft::normal_iterator<Iterator, Container>(this->memory_current++));
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>& ft::normal_iterator<Iterator, Container>::operator--(void) {
    --this->memory_current;
    return (*this);
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container> ft::normal_iterator<Iterator, Container>::operator--(int) {
    return (ft::normal_iterator<Iterator, Container>(this->memory_current--));
}

template<typename Iterator, typename Container>
typename ft::normal_iterator<Iterator, Container>::reference ft::normal_iterator<Iterator, Container>::operator[](const difference_type& n) const {
    return (this->memory_current[n]);
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>& ft::normal_iterator<Iterator, Container>::operator+=(const difference_type& n) {
    this->memory_current += n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container>& ft::normal_iterator<Iterator, Container>::operator-=(const difference_type& n) {
    this->memory_current -= n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container> ft::normal_iterator<Iterator, Container>::operator+(const difference_type& n) const {
    return (ft::normal_iterator<Iterator, Container>(this->memory_current + n));
}

template<typename Iterator, typename Container>
ft::normal_iterator<Iterator, Container> ft::normal_iterator<Iterator, Container>::operator-(const difference_type& n) const {
    return (ft::normal_iterator<Iterator, Container>(this->memory_current - n));
}

template<typename Iterator, typename Container>
const Iterator& ft::normal_iterator<Iterator, Container>::base(void) const {
    return (this->memory_current);
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator==(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator==(
    const ft::normal_iterator<Iterator, Container>& lhs,
    const ft::normal_iterator<Iterator, Container>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator!=(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator!=(
    const ft::normal_iterator<Iterator, Container>& lhs,
    const ft::normal_iterator<Iterator, Container>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator<(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() < rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator<(
    const ft::normal_iterator<Iterator, Container>& lhs,
    const ft::normal_iterator<Iterator, Container>& rhs) {
        return (lhs.base() < rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator>(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() > rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator>(
    const ft::normal_iterator<Iterator, Container>& lhs,
    const ft::normal_iterator<Iterator, Container>& rhs) {
        return (lhs.base() > rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator<=(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() <= rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator<=(
    const ft::normal_iterator<Iterator, Container>& lhs,
    const ft::normal_iterator<Iterator, Container>& rhs) {
        return (lhs.base() <= rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator>=(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() >= rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator>=(
    const ft::normal_iterator<Iterator, Container>& lhs,
    const ft::normal_iterator<Iterator, Container>& rhs) {
        return (lhs.base() >= rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::normal_iterator<IteratorL, Container>::difference_type ft::operator-(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() - rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::normal_iterator<IteratorL, Container>::difference_type ft::operator+(
    typename ft::normal_iterator<IteratorL, Container>::difference_type n,
    const ft::normal_iterator<IteratorR, Container>& i) {
        return (ft::normal_iterator<IteratorL, Container>(i.base() + n));
}
