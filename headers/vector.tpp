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
    for (; n > 0; n--, curr++) {
        this->get_allocator().construct(curr, value);
    }
    this->memoryImpl.memoryFinish = this->memoryImpl.memoryStart + n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc) : VectorBase<T, Alloc>(alloc) {
    typedef typename ft::iteratorTraits<iterator>::iterator_category iterator_category;
    this->memoryRangeInitialize(first, last, iterator_category());
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memoryRangeInitialize(iterator first, iterator last, ft::input_iterator_tag) {
    // const size_type __n = std::distance(__first, __last);
    // this->_M_impl._M_start = this->_M_allocate(__n);
    // this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
    // this->_M_impl._M_finish =
    // std::__uninitialized_copy_a(__first, __last,
	// 				this->_M_impl._M_start,
	// 				this->get_allocator());
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
