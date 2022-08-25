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
    ft::vector<int> lhs(10, 10);
    ft::vector<int> rhs(15, 15);
    lhs = rhs;
    typename ft::vector<int>::iterator it;
    it = lhs.begin();
    for (int i = 0; i < 10; ++i, ++it)
        std::cout << *it << std::endl;
    print_test(lhs);



    // std::vector<int> lhs(10, 10);
    // std::vector<int> rhs(15, 15);
    // lhs.push_back(100);
    // std::cout << "lhs capacity: " << lhs.capacity() << std::endl;
    // std::cout << "lhs size: " << lhs.size() << std::endl;
    // std::cout << "rhs size: " << rhs.size() << std::endl;

    // std::cout << std::distance(rhs.begin() + lhs.size(), rhs.end()) << std::endl;

    return (0);
}

