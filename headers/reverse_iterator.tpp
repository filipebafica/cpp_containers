// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./reverse_iterator.hpp"

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator() : normal_iterator<Iterator, Container>() {
    std::cout << "Reverse Iterator default constructor called" << std::endl;
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator(const Iterator& i) : normal_iterator<Iterator, Container>(i) {
    std::cout << "Reverse Iterator fill constructor called" << std::endl;
}

template<typename Iterator, typename Container>
ft::reverse_iterator<Iterator, Container>::reverse_iterator(const reverse_iterator& src) : normal_iterator<Iterator, Container>() {
    std::cout << "Reverse Iterator copy constructor called" << std::endl;
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
