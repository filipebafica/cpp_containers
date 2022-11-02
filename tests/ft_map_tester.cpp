// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <functional>
#include <map>
#include "../headers/map.hpp"
#include "../headers/vector.hpp"

void erase_methods_test(void) {
    std::cout << std::endl << "[ERASE METHODS TEST]" << std::endl;
    ft::map<int, int> ft_1;
    {
        for (int i = 0; i < 10; i++) {
            ft_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "erase(iterator position)" << std::endl;
        std::cout << "before erasing iterator begin(): " << ft_1.begin()->first << std::endl;
        ft_1.memory_tree.print_tree_debug();
        ft_1.erase(ft_1.begin());
        std::cout << std::endl << "after:" << std::endl;
        ft_1.memory_tree.print_tree_debug();
    }
    {
        for (int i = 0; i < 10; i++) {
            ft_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "erase(iterator first, iterator last)" << std::endl;
        std::cout << "before erasing from iterator begin() to iterator end():" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
        ft_1.erase(ft_1.begin(), ft_1.end());
        std::cout << "after:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
    }
    {
        for (int i = 0; i < 10; i++) {
            ft_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "erase(const key_type& k)" << std::endl;
        std::cout << "before erasing key 5:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
        std::cout << "number of elements erased: " << ft_1.erase(5) << std::endl;
        std::cout << "after:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;

        std::cout << "erase(const key_type& k)" << std::endl;
        std::cout << "before erasing key 99:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
        std::cout << "number of elements erased: " << ft_1.erase(99) << std::endl;
        std::cout << "after:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
    }
    {
        for (int i = 0; i < 10; i++) {
            ft_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "clear(void)" << std::endl;
        std::cout << "before clear:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
        ft_1.clear();
        std::cout << "after:" << std::endl;
        std::cout << "size(): " << ft_1.size() << std::endl;
    }
}

void capacity_methods_test(void) {
    std::cout << std::endl << "[CAPACITY METHODS TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << ft_1.empty() << std::endl;
    std::cout << ft_1.size() << std::endl;
    std::cout << ft_1.max_size() << std::endl;
}

void end_method_test(void) {
    std::cout << std::endl << "[END METHOD TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }
    const ft::map<int, int> ft_2(ft_1.begin(), ft_1.end());

    std::cout << (*--ft_2.end()).first << std::endl;
    std::cout << (*--ft_1.end()).first << std::endl;

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}

void begin_method_test(void) {
    std::cout << std::endl << "[BEGIN METHOD TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }
    const ft::map<int, int> ft_2(ft_1.begin(), ft_1.end());

    std::cout << (*ft_2.begin()).first << std::endl;
    std::cout << (*ft_1.begin()).first << std::endl;
}

void at_method_test(void) {
    std::cout << std::endl << "[AT METHOD TEST]" << std::endl;
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
    std::cout << std::endl << "[ACCESS OPERATOR TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << ft_1[0] << std::endl;
    std::cout << ft_1[5] << std::endl;
    std::cout << ft_1[100] << std::endl;
}

void assignment_operator_test(void) {
    std::cout << std::endl << "[ASSIGNMENT OPERATOR TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2 = ft_1;

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}

void copy_constructor_test(void) {
    std::cout << std::endl << "[COPY CONSTRUCTOR TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2(ft_1);

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}

void range_constructor_test(void) {
    std::cout << "[RANGE CONSTRUCTOR TEST]" << std::endl;
    ft::map<int, int> ft_1;

    for (int i = 0; i < 10; i++) {
        ft_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> ft_2(ft_1.begin(), ft_1.end());

    ft_1.memory_tree.print_tree_debug();
    ft_2.memory_tree.print_tree_debug();
}


int main(void) {
    range_constructor_test();
    copy_constructor_test();
    assignment_operator_test();
    access_operator_test();
    at_method_test();
    begin_method_test();
    end_method_test();
    capacity_methods_test();
    erase_methods_test();
    return (0);
}
