// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <functional>
#include <map>
#include "../headers/map.hpp"
#include "../headers/vector.hpp"

int main(void) {
    ft::map<char, int> x;
    std::map<char, int> y;
    // std::map<char, int>::iterator z;
    ft::pair<ft::map<char, int>::iterator, bool> i;
    std::pair<std::map<char, int>::iterator, bool> j;

    i = x.insert(ft::pair<char, int>('a', 1));
    j = y.insert(std::pair<char, int>('a', 1));
    x.insert(ft::pair<char, int>('b', 2));
    y.insert(std::pair<char, int>('b', 2));

    std::cout << (++i.first)->first << std::endl;
    std::cout << (++j.first)->first << std::endl;
    return (0);
}
