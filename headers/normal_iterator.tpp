// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./normal_iterator.hpp"

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>::NormalIterator() : memoryCurrent(Iterator()) {
    std::cout << "Default normalIterator constructor called" << std::endl;
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>::NormalIterator(const Iterator& i) : memoryCurrent(Iterator(i)) {
    std::cout << "Fill normalIterator constructor called" << std::endl;
}

template<typename Iterator, typename Container>
typename ft::NormalIterator<Iterator, Container>::reference ft::NormalIterator<Iterator, Container>::operator*(void) const {
    return (*this->memoryCurrent);
}

template<typename Iterator, typename Container>
typename ft::NormalIterator<Iterator, Container>::pointer ft::NormalIterator<Iterator, Container>::operator->(void) const {
    return (this->memoryCurrent);
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>& ft::NormalIterator<Iterator, Container>::operator++(void) {
    ++this->memoryCurrent;
    return (*this);
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container> ft::NormalIterator<Iterator, Container>::operator++(int) {
    return (ft::NormalIterator<Iterator, Container>(this->memoryCurrent++));
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>& ft::NormalIterator<Iterator, Container>::operator--(void) {
    --this->memoryCurrent;
    return (*this);
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container> ft::NormalIterator<Iterator, Container>::operator--(int) {
    return (ft::NormalIterator<Iterator, Container>(this->memoryCurrent--));
}

template<typename Iterator, typename Container>
typename ft::NormalIterator<Iterator, Container>::reference ft::NormalIterator<Iterator, Container>::operator[](const difference_type& n) const {
    return (this->memoryCurrent[n]);
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>& ft::NormalIterator<Iterator, Container>::operator+=(const difference_type& n) {
    this->memoryCurrent += n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>& ft::NormalIterator<Iterator, Container>::operator-=(const difference_type& n) {
    this->memoryCurrent -= n;
    return (*this);
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container> ft::NormalIterator<Iterator, Container>::operator+(const difference_type& n) const {
    return (ft::NormalIterator<Iterator, Container>(this->memoryCurrent + n));
}

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container> ft::NormalIterator<Iterator, Container>::operator-(const difference_type& n) const {
    return (ft::NormalIterator<Iterator, Container>(this->memoryCurrent - n));
}

template<typename Iterator, typename Container>
const Iterator& ft::NormalIterator<Iterator, Container>::base(void) const {
    return (this->memoryCurrent);
}

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::NormalIterator<IteratorL, Container>::difference_type ft::operator-(
    const ft::NormalIterator<IteratorL, Container>& lhs,
    const ft::NormalIterator<IteratorR, Container>& rhs) {
        return (lhs.base() - rhs.base());
}

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::NormalIterator<IteratorL, Container>::difference_type ft::operator+(
    typename ft::NormalIterator<IteratorL, Container>::difference_type n,
    const ft::NormalIterator<IteratorR, Container>& i) {
        return (ft::NormalIterator<IteratorL, Container>(i.base() + n));
}
