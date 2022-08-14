// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector.hpp"

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : VectorBase<T, Alloc>(alloc) {
    std::cout << "Empty Vector constructor called" << std::endl;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) : VectorBase<T, Alloc>(n, alloc) {
    std::cout << "Fill Vector constructor called" << std::endl;
    T* curr = this->memoryImpl.memoryStart;
    for (; n > 0; n--, curr++) {
        const_cast<allocator_type&>(alloc).construct(curr, value);
    }
    this->memoryImpl.memoryFinish = this->memoryImpl.memoryStart + n;
}
