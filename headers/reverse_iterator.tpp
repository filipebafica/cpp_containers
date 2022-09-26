// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./reverse_iterator.hpp"

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator() : normal_iterator<Iterator, Container>() {
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator(const Iterator& i) : normal_iterator<Iterator, Container>(i) {
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator(const reverse_iterator& src) : normal_iterator<Iterator, Container>() {
    *this = src;
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator=(const reverse_iterator& src) {
    this->memory_current = src.base();
    return (*this);
}

template<typename Iterator, typename Container>
typename ft::reverse_iterator<Iterator, Container>::reference ft::reverse_iterator<Iterator, Container>::operator*(void) const {
    Iterator tmp = this->memory_current;
    return (*--tmp);
}

template<typename Iterator, typename Container>
typename ft::reverse_iterator<Iterator, Container>::pointer ft::reverse_iterator<Iterator, Container>::operator->(void) const {
    return (&(operator*()));
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator++(void) {
    --this->memory_current;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator++(int) {
    reverse_iterator tmp = *this;
    --this->memory_current;
    return (tmp);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator--(void) {
    ++this->memory_current;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator--(int) {
    reverse_iterator tmp = *this;
    ++this->memory_current;
    return (tmp);
}

template<typename Iterator, typename Container>
typename ft::reverse_iterator<Iterator, Container>::reference ft::reverse_iterator<Iterator, Container>::operator[](const difference_type& n) const {
    return (this->memory_current[n]);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator+=(const difference_type& n) {
    this->memory_current -= n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>& ft::reverse_iterator<Iterator, Container>::operator-=(const difference_type& n) {
    this->memory_current += n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator+(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator, Container>(this->memory_current - n));
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container> ft::reverse_iterator<Iterator, Container>::operator-(const difference_type& n) const {
    return (ft::reverse_iterator<Iterator, Container>(this->memory_current + n));
}
