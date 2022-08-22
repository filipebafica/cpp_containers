// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"

int main(void) {
    ft::vector<int> v1(10);
    ft::vector<int> v2(v1.begin(), v1.end());
    typename ft::vector<int>::iterator it;
    it = v2.begin();
    for (int i = 0; i < 10; ++i, ++it)
        std::cout << *it << std::endl;
    return (0);
}

