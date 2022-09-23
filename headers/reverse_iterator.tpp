// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./reverse_iterator.hpp"

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : memory_current(Iterator()) {
    std::cout << "Reverse Iterator default constructor called" << std::endl;
}

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(const Iterator& i) : memory_current(Iterator(i)) {
    std::cout << "Reverse Iterator fill constructor called" << std::endl;
}

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator& src) : memory_current(src.base()) {
    std::cout << "Reverse Iterator copy constructor called" << std::endl;
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*(void) const {
    
    return (*this->memory_current);
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::pointer ft::reverse_iterator<Iterator>::operator->(void) const {
    return (this->memory_current);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator++(void) {
    ++this->memory_current;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator++(int) {
    return (ft::reverse_iterator<Iterator>(this->memory_current++));
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator--(void) {
    --this->memory_current;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator--(int) {
    return (ft::reverse_iterator<Iterator>(this->memory_current--));
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator[](const difference_type& n) const {
    return (this->memory_current[n]);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator+=(const difference_type& n) {
    this->memory_current += n;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator-=(const difference_type& n) {
    this->memory_current -= n;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator+(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator>(this->memory_current + n));
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator-(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator>(this->memory_current - n));
}

template<typename Iterator>
const Iterator& ft::reverse_iterator<Iterator>::base(void) const {
    return (this->memory_current);
}

template<typename IteratorL, typename IteratorR>
bool ft::operator==(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename Iterator>
bool ft::operator==(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return (lhs.base() == rhs.base());
}

template<typename IteratorL, typename IteratorR>
bool ft::operator!=(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename Iterator>
bool ft::operator!=(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return (lhs.base() != rhs.base());
}

template<typename IteratorL, typename IteratorR>
bool ft::operator<(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() < rhs.base());
}

template<typename Iterator>
bool ft::operator<(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return (lhs.base() < rhs.base());
}

template<typename IteratorL, typename IteratorR>
bool ft::operator>(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() > rhs.base());
}

template<typename Iterator>
bool ft::operator>(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return (lhs.base() > rhs.base());
}

template<typename IteratorL, typename IteratorR>
bool ft::operator<=(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() <= rhs.base());
}

template<typename Iterator>
bool ft::operator<=(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return (lhs.base() <= rhs.base());
}

template<typename IteratorL, typename IteratorR>
bool ft::operator>=(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() >= rhs.base());
}

template<typename Iterator>
bool ft::operator>=(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return (lhs.base() >= rhs.base());
}

template<typename IteratorL, typename IteratorR>
typename ft::reverse_iterator<IteratorL>::difference_type ft::operator-(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs) {
        return (lhs.base() - rhs.base());
}

template<typename IteratorL, typename IteratorR>
typename ft::reverse_iterator<IteratorL>::difference_type ft::operator+(
    typename ft::reverse_iterator<IteratorL>::difference_type n,
    const ft::reverse_iterator<IteratorR>& i) {
        return (ft::reverse_iterator<IteratorL>(i.base() + n));
}
