// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector_base.hpp"

template<class T, class Alloc>
ft::VectorBase<T, Alloc>::VectorBase(const allocator_type& alloc) : memoryImpl(alloc) {
    std::cout << "Default vector base constructor called" << std::endl;
}

template<class T, class Alloc>
ft::VectorBase<T, Alloc>::VectorBase(size_t n, const allocator_type& alloc) : memoryImpl(alloc) {
    std::cout << "Fill vector base constructor called" << std::endl;
    this->memoryImpl.memoryStart = this->memoryAllocate(n);
    this->memoryImpl.memoryFinish = this->memoryImpl.memoryStart;
    this->memoryImpl.memoryEndOfStorage = this->memoryImpl.memoryStart + n;
}

template<class T, class Alloc>
ft::VectorBase<T, Alloc>::~VectorBase(void) {
    std::cout << "Default vector base destructor called" << std::endl;
    this->memoryDeallocate(this->memoryImpl.memoryStart, 
    this->memoryImpl.memoryEndOfStorage - this->memoryImpl.memoryStart);
}

template<class T, class Alloc>
Alloc ft::VectorBase<T, Alloc>::get_allocator(void) const {
    return (this->memoryImpl);
};

template<class T, class Alloc>
T* ft::VectorBase<T, Alloc>::memoryAllocate(size_t n) {
    return (this->memoryImpl.allocate(n));
}

template<class T, class Alloc>
void ft::VectorBase<T, Alloc>::memoryDeallocate(T* memoryStart, size_t n) {
    this->memoryImpl.deallocate(memoryStart, n);
}
