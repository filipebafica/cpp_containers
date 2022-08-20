// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"


// int main(void) {
    // std::vector<int> v;
//     for (int i = 0; i < 10; ++i) {
//         v.insert(v.end(), i);
//     }
//     for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
//         std::cout << *it << std::endl;
//     }
//     std::vector<int> v2(v.begin(), v.end());
//     for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
//         std::cout << *it << std::endl;
//     }
//     return (0);
// }

int main(void) {
    ft::vector<int> v1(10);
    ft::vector<int> v2(v1.begin(), v2.end());

    return (0);
}

