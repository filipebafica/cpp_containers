// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./ft_vector.hpp"

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : VectorBase<T, Alloc>(alloc) {
    std::cout << "Empty Vector constructor called" << std::endl;
}
