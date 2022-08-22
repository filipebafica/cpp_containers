// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector.hpp"

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : VectorBase<T, Alloc>(alloc) {
    std::cout << "Empty vector constructor called" << std::endl;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) : VectorBase<T, Alloc>(n, alloc) {
    std::cout << "Fill vector constructor called" << std::endl;
    T* curr = this->memoryImpl.memoryStart;
    for (size_type i = n; i > 0; i--, curr++) {
        this->get_allocator().construct(curr, value);
    }
    this->memoryImpl.memoryFinish = this->memoryImpl.memoryStart + n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc) : VectorBase<T, Alloc>(std::distance(first, last), alloc) {
    std::cout << "Range vector constructor called" << std::endl;
    typedef typename ft::iteratorTraits<iterator>::iterator_category iterator_category;
    this->memoryRangeInitialize(first, last, iterator_category());
}

// template<class T, class Alloc>
// void ft::vector<T, Alloc>::memoryRangeInitialize(iterator first, iterator last, std::input_iterator_tag) {
//     for (; first != last; ++first) {
//         this->push_back(*first);
//     }
// }

template<class T, class Alloc>
void ft::vector<T, Alloc>::memoryRangeInitialize(iterator first, iterator last, std::forward_iterator_tag) {
    const size_type n = std::distance(first, last);
    T* curr = this->memoryImpl.memoryStart;
    for (int i = n; i > 0; i--, curr++, first++) {
        this->get_allocator().construct(curr, *first);
    }
    this->memoryImpl.memoryFinish = this->memoryImpl.memoryStart + n;
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin(void) {
    return (iterator(this->memoryImpl.memoryStart));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end(void) {
    return (iterator(this->memoryImpl.memoryFinish));
}

template<class T, class Alloc>
ft::vector<T, Alloc>::~vector(void) {
    std::cout << "Default vector destructor called" << std::endl;
    T* curr = this->memoryImpl.memoryStart;
    T* last = this->memoryImpl.memoryEndOfStorage;
    for (; curr != last; curr++) {
        this->get_allocator().destroy(this->memoryImpl.memoryStart);
    }
}
