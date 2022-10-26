// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <functional>
#include <map>
#include "../headers/map.hpp"
#include "../headers/vector.hpp"


void range_constructor_test(void) {
    ft::map<int, int> ft_1;
    std::map<int, int> std_1;


    ft::pair<ft::map<int, int>::iterator, bool> ft_first;
    ft::pair<ft::map<int, int>::iterator, bool> ft_last;
    std::pair<std::map<int, int>::iterator, bool> std_first;
    std::pair<std::map<int, int>::iterator, bool> std_last;


    ft_first = ft_1.insert(ft::pair<int, int>(0, 0));
    std_first = std_1.insert(std::pair<int, int>(0, 0));

    for (int i = 0; i < 10; i++) {
        ft_last = ft_1.insert(ft::pair<int, int>(i, i));
        std_last = std_1.insert(std::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2(ft_first.first, ft_last.first);
    std::map<int, int> std_2(std_first.first, std_last.first);
}


int main(void) {
    range_constructor_test();
    return (0);
}
