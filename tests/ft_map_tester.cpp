// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <functional>
#include <map>
#include "../headers/map.hpp"
#include "../headers/vector.hpp"

void at_test(void) {
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << ft_1.at(0) << std::endl;
    std::cout << ft_1.at(5) << std::endl;
    try {
        ft_1.at(100);
    }
    catch(std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

void access_operator_test(void) {
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << ft_1[0] << std::endl;
    std::cout << ft_1[5] << std::endl;
    std::cout << ft_1[100] << std::endl;
}

void assignment_operator_test(void) {
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2 = ft_1;

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}

void copy_constructor_test(void) {
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2(ft_1);

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}

void range_constructor_test(void) {
    ft::map<int, int> ft_1;

    ft::pair<ft::map<int, int>::iterator, bool> ft_first;
    ft::pair<ft::map<int, int>::iterator, bool> ft_last;

    ft_first = ft_1.insert(ft::pair<int, int>(0, 0));

    for (int i = 0; i < 10; i++) {
        ft_last = ft_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2(ft_first.first, ft_last.first);

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}


int main(void) {
    range_constructor_test();
    copy_constructor_test();
    assignment_operator_test();
    access_operator_test();
    at_test();
    return (0);
}
