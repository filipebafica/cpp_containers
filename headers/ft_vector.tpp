// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./ft_vector.hpp"

template<class T, class Alloc >
ft::vector<T, Alloc>::vector(void) {
    std::cout << "Default constructor called for a vector" << std::endl;
}

template<class T, class Alloc >
ft::vector<T, Alloc>::vector(const allocator_type& alloc) {
    std::cout << "Empty container constructor called for a vector" << std::endl;
}
