// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"
#include "../headers/type_traits.hpp"

// void print_test(ft::vector<int> v) {
//     typename ft::vector<int>::iterator first;
//     typename ft::vector<int>::iterator last;
//     first = v.begin();
//     last = v.end();
//     for (; first != last; ++first)
//         std::cout << *first << std::endl;
// }


int main(void) {
    // ft::vector<int> v(10);

    // std::cout << v.size() << std::endl;
    // v.resize(5);
    // std::cout << v.size() << std::endl;
    std::vector<int> v(5);
    v.insert(v.end(), 10);
    v.insert(v.end(), 11);
    v.insert(v.end(), 12);
    v.insert(v.end(), 13);
    v.insert(v.end(), 14);
    // typename std::vector<int>::reverse_iterator rit;
    std::vector<int>::reverse_iterator rit;

    rit = v.rbegin();

    // std::cout << *rit << std::endl;
    // std::cout << *rit << std::endl;
    return (0);
}
