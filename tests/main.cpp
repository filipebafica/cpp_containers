// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"

void print_test(ft::vector<int> v) {
    typename ft::vector<int>::iterator it;
    it = v.begin();
    for (int i = 0; i < 11; ++i, ++it)
        std::cout << *it << std::endl;
}

int main(void) {
    ft::vector<int> lhs(10, 10);
    typename ft::vector<int>::iterator it;
    it = lhs.begin();
    for (int i = 0; i < 10; ++i, ++it)
        std::cout << *it << std::endl;
    lhs.assign(1, 5);
    print_test(lhs);
    // std::vector<int> v;
    // v.erase()
    return (0);
}
