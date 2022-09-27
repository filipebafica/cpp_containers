// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./reverse_iterator.hpp"

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : memory_current() {
}

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(const iterator_type& i) : memory_current(i) {
}

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator& src) {
    *this = src;
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator=(const reverse_iterator& src) {
    this->memory_current = src.base();
    return (*this);
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*(void) const {
    Iterator tmp = this->memory_current;
    return (*--tmp);
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::pointer ft::reverse_iterator<Iterator>::operator->(void) const {
    return (&(operator*()));
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator++(void) {
    --this->memory_current;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator++(int) {
    reverse_iterator tmp = *this;
    --this->memory_current;
    return (tmp);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator--(void) {
    ++this->memory_current;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator--(int) {
    reverse_iterator tmp = *this;
    ++this->memory_current;
    return (tmp);
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator[](const difference_type& n) const {
    return (this->memory_current[n]);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator+=(const difference_type& n) {
    this->memory_current -= n;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator-=(const difference_type& n) {
    this->memory_current += n;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator+(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator>(this->memory_current - n));
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator-(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator>(this->memory_current + n));
}
