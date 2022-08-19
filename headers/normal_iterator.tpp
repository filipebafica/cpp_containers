// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./normal_iterator.hpp"

template<typename Iterator, typename Container>
ft::NormalIterator<Iterator, Container>::NormalIterator() : memoryCurrent(Iterator()) {
    std::cout << "Default normalIterator constructor called" << std::endl;
}
