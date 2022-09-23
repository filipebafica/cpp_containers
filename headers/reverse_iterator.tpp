// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./reverse_iterator.hpp"

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator() : memory_current(Iterator()) {
    std::cout << "Reverse Iterator default constructor called" << std::endl;
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator(const Iterator& i) : memory_current(Iterator(i)) {
    std::cout << "Reverse Iterator fill constructor called" << std::endl;
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator(const reverse_iterator& src) : memory_current(src.base()) {
    std::cout << "Reverse Iterator copy constructor called" << std::endl;
}

template<typename Iterator, typename Container>
typename ft::reverse_iterator<Iterator, Container>::reference ft::reverse_iterator<Iterator, Container>::operator*(void) const {
    return (*this->memory_current);
}

template<typename Iterator, typename Container>
typename ft::reverse_iterator<Iterator, Container>::pointer ft::reverse_iterator<Iterator, Container>::operator->(void) const {
    return (this->memory_current);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator++(void) {
    ++this->memory_current;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator++(int) {
    return (ft::reverse_iterator<Iterator, Container>(this->memory_current++));
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator--(void) {
    --this->memory_current;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator--(int) {
    return (ft::reverse_iterator<Iterator, Container>(this->memory_current--));
}

template<typename Iterator, typename Container>
typename ft::reverse_iterator<Iterator, Container>::reference ft::reverse_iterator<Iterator, Container>::operator[](const difference_type& n) const {
    return (this->memory_current[n]);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator+=(const difference_type& n) {
    this->memory_current += n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator-=(const difference_type& n) {
    this->memory_current -= n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator+(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator, Container>(this->memory_current + n));
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator-(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator, Container>(this->memory_current - n));
}

template<typename Iterator, typename Container>
const Iterator& ft::reverse_iterator<Iterator, Container>::base(void) const {
    return (this->memory_current);
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator==(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator==(
    const ft::reverse_iterator<Iterator, Container>& lhs,
    const ft::reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator!=(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator!=(
    const ft::reverse_iterator<Iterator, Container>& lhs,
    const ft::reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator<(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() < rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator<(
    const ft::reverse_iterator<Iterator, Container>& lhs,
    const ft::reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() < rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator>(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() > rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator>(
    const ft::reverse_iterator<Iterator, Container>& lhs,
    const ft::reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() > rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator<=(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() <= rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator<=(
    const ft::reverse_iterator<Iterator, Container>& lhs,
    const ft::reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() <= rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
bool ft::operator>=(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() >= rhs.base());
}

template<typename Iterator, typename Container>
bool ft::operator>=(
    const ft::reverse_iterator<Iterator, Container>& lhs,
    const ft::reverse_iterator<Iterator, Container>& rhs) {
        return (lhs.base() >= rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::reverse_iterator<IteratorL, Container>::difference_type ft::operator-(
    const ft::reverse_iterator<IteratorL, Container>& lhs,
    const ft::reverse_iterator<IteratorR, Container>& rhs) {
        return (lhs.base() - rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::reverse_iterator<IteratorL, Container>::difference_type ft::operator+(
    typename ft::reverse_iterator<IteratorL, Container>::difference_type n,
    const ft::reverse_iterator<IteratorR, Container>& i) {
        return (ft::reverse_iterator<IteratorL, Container>(i.base() + n));
}
