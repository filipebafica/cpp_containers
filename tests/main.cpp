// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"

void print_test(std::vector<int> v) {
    typename std::vector<int>::iterator first;
    typename std::vector<int>::iterator last;
    first = v.begin();
    last = v.end();
    for (; first != last; ++first)
        std::cout << *first << std::endl;
}


int main(void) {
    std::vector<int> lhs(10, 10);

    // typename ft::vector<int>::iterator it;
    // it = lhs.begin();
    // for (int i = 0; i < 10; ++i, ++it)
    //     std::cout << *it << std::endl;
    // lhs.assign(1, 5);
    // print_test(lhs);
    std::cout << lhs.capacity() << std::endl;
    // lhs.insert(lhs.end(), 10);
    // std::cout << lhs.capacity() << std::endl;
    lhs.insert(lhs.begin(), 10, 18);
    std::cout << lhs.capacity() << std::endl;
    print_test(lhs);
    return (0);
}
