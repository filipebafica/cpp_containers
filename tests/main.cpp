// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"

void print_test(ft::vector<int> v) {
    typename ft::vector<int>::iterator it;
    it = v.begin();
    for (int i = 0; i < 10; ++i, ++it)
        std::cout << *it << std::endl;
}

int main(void) {
    ft::vector<int> v1(10, 10);
    typename ft::vector<int>::iterator it;
    it = v1.begin();
    for (int i = 0; i < 10; ++i, ++it)
        std::cout << *it << std::endl;
    print_test(v1);
    return (0);
}

