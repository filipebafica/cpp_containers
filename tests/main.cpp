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
    // ft::vector<int> lhs(10, 10);

    // typename ft::vector<int>::iterator it;
    // it = lhs.begin();
    // for (int i = 0; i < 10; ++i, ++it)
    //     std::cout << *it << std::endl;
    // lhs.assign(1, 5);
    // print_test(lhs);
    // std::cout << lhs.capacity() << std::endl;
    // // lhs.insert(lhs.end(), 10);
    // // std::cout << lhs.capacity() << std::endl;
    // lhs.insert(lhs.begin(), 20, 18);
    // std::cout << lhs.capacity() << std::endl;
    // print_test(lhs);
    std::cout << "is_integral:" << std::endl;
    std::cout << "char: " << ft::is_integral<char>::value << std::endl;
    std::cout << "int: " << ft::is_integral<int>::value << std::endl;
    std::cout << "float: " << ft::is_integral<float>::value << std::endl;

    return (0);
}
