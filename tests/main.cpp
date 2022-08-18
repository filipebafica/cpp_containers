// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"


int main(void) {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.insert(v.end(), i);
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "0 appears: " << std::count(v.begin(), v.end(), 0) << std::endl;
    return (0);
}

