// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./ft_vector_base.hpp"

template<class T, class Alloc >
ft::VectorBase<T, Alloc>::VectorBase(const allocator_type& alloc) : memoryImpl(alloc) {
    std::cout << "Default Vector Base constructor called" << std::endl;
}
