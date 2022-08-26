// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector_base.hpp"

template<class T, class Alloc>
ft::vector_base<T, Alloc>::vector_base(const allocator_type& alloc) : memory_impl(alloc) {
    std::cout << "Vector Base default base constructor called" << std::endl;
}

template<class T, class Alloc>
ft::vector_base<T, Alloc>::vector_base(size_t n, const allocator_type& alloc) : memory_impl(alloc) {
    std::cout << "Vector Base fill constructor called" << std::endl;
    this->memory_impl.memory_start = this->memory_allocate(n);
    this->memory_impl.memory_finish = this->memory_impl.memory_start;
    this->memory_impl.memory_end_of_storage = this->memory_impl.memory_start + n;
}

template<class T, class Alloc>
ft::vector_base<T, Alloc>::~vector_base(void) {
    std::cout << "Vector Base default  destructor called" << std::endl;
    this->memory_deallocate(this->memory_impl.memory_start, 
    this->memory_impl.memory_end_of_storage - this->memory_impl.memory_start);
}

template<class T, class Alloc>
Alloc ft::vector_base<T, Alloc>::get_allocator(void) const {
    return (this->memory_impl);
};

template<class T, class Alloc>
T* ft::vector_base<T, Alloc>::memory_allocate(size_t n) {
    return (this->memory_impl.allocate(n));
}

template<class T, class Alloc>
void ft::vector_base<T, Alloc>::memory_deallocate(T* memory_start, size_t n) {
    if (memory_start)
        this->memory_impl.deallocate(memory_start, n);
}
