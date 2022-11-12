// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"
#include "../headers/type_traits.hpp"

void default_constructor_test(void) {
    std::cout << "[DEFAULT CONSTRUCTOR TEST]" << std::endl;
    std::vector<int> v0;
    std::vector<float> v1;
    std::vector<char> v2;
}

void fill_constructor_test(void) {
    std::cout << std::endl << "[FILL CONSTRUCTOR TEST]" << std::endl;
    std::vector<int> v0(1000, 1);
    std::vector<float> v1(1000, 1.1);
    std::vector<char> v2(1000, 'a');

    std::cout << "size of v0: " << v0.size() << std::endl
              << "size of v1: " << v1.size() << std::endl
              << "size of v2: " << v2.size() << std::endl;
}

void range_constructor_test(void) {
    std::cout << std::endl << "[RANGE CONSTRUCTOR TEST]" << std::endl;
    std::vector<int> v0(1000, 1);
    std::vector<int> v1(v0.begin(), v0.end());

    std::cout << "size of v0: " << v0.size() << std::endl
              << "size of v1: " << v1.size() << std::endl;
}

void assignment_operator_test(void) {
    std::cout << std::endl << "[ASSIGNMENT OPERATOR TEST]" << std::endl;
    std::vector<int> v0(1000, 1);
    std::vector<int> v1;
    v1 = v0;

    std::cout << "size of v0: " << v0.size() << std::endl
              << "size of v1: " << v1.size() << std::endl;
}

void access_operator_test(void) {
    try {
        std::cout << std::endl << "[ACCESS OPERATOR TEST]" << std::endl;
        std::vector<int> v0(10, 1);
        std::cout << "v0[5]: " << v0[5] << std::endl;
    }
    catch(...) {
        std::cout << "* '[]' operator exception *" << std::endl;
    }
}

void at_method_test(void) {
    try {
        std::cout << std::endl << "[AT METHOD TEST]" << std::endl;
        std::vector<int> v0(10, 1);
        std::cout << "v0.at(5): " << v0.at(5) << std::endl;
    }
    catch(...) {
        std::cout << "* At method exception *" << std::endl;
    }
}

void front_method_test(void) {
    std::cout << std::endl << "[FRONT METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "v0.front(): " << v0.front() << std::endl;
}

void back_method_test(void) {
    std::cout << std::endl << "[BACK METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "v0.back(): " << v0.back() << std::endl;
}

void data_method_test(void) {
    std::cout << std::endl << "[DATA METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "*v0.data(): " << *v0.data() << std::endl;
}

void empty_method_test(void) {
    std::cout << std::endl << "[EMPTY METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "v0.empty(): " << v0.empty() << std::endl;
}

void size_method_test(void) {
    std::cout << std::endl << "[SIZE METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "v0.size(): " << v0.size() << std::endl;
}

void max_size_method(void) {
    std::cout << std::endl << "[MAX_SIZE METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "v0.max_size(): " << v0.max_size() << std::endl;
}

void capacity_method_test(void) {
    std::cout << std::endl << "[CAPACITY METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "v0.capacity(): " << v0.capacity() << std::endl;
}

void reserve_method_test(void) {
    std::cout << std::endl << "[RESERVE METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "before v0.reserve(100) capacity is: " << v0.capacity() << std::endl;
    v0.reserve(100);
    std::cout << "after v0.reserve(100) capacity is: " << v0.capacity() << std::endl;
}

void assign_method_test(void) {
    {
        std::cout << std::endl << "[ASSIGN METHOD TEST (FILL)] " << std::endl;
        std::vector<int> v0;
        v0.assign(5, 1);
        std::cout << "v0.assign(5, 1): ";
        for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[ASSIGN METHOD TEST (RANGE)] " << std::endl;
        std::vector<int> v0(5, 1);
        std::vector<int> v1;
        v1.assign(v0.begin(), v0.end());
        std::cout << "v0.assign(5, 1): ";
        for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

void clear_method_test(void) {
    std::cout << std::endl << "[CLEAR METHOD TEST]" << std::endl;
    std::vector<int> v0(10, 1);
    std::cout << "before v0.clear() size is: " << v0.size() << std::endl;
    v0.clear();
    std::cout << "after v0.clear() size is: " << v0.size() << std::endl;
}

void insert_method_test(void) {
    {
        std::cout << std::endl << "[INSERT METHOD TEST (POSITION, VALUE)]" << std::endl;
        std::vector<int> v0;
        v0.insert(v0.begin(), 10);
        std::cout << "v0.insert(v0.begin(), 10): " << *v0.begin() << std::endl;
        v0.insert(v0.end(), 10);
        std::cout << "v0.insert(v0.end(), 10): " << *--v0.end() << std::endl;
    }

    {
        std::cout << std::endl << "[INSERT METHOD TEST (POSITION, N, VALUE)]" << std::endl;
        {
            std::vector<int> v0;
            v0.insert(v0.begin(), 5, 1);
            std::cout << "v0.insert(v0.begin(), 5, 1): ";
            for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        {
            std::vector<int> v0;
            v0.insert(v0.end(), 5, 1);
            std::cout << "v0.insert(v0.end(), 5, 1): ";
            for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
    }

    {
        std::cout << std::endl << "[INSERT METHOD TEST (POSITION, FIRST, LAST)]" << std::endl;
        {
            std::vector<int> v0_base(5, 1);
            std::vector<int> v0;
            v0.insert(v0.begin(), v0_base.begin(), v0_base.end());
            std::cout << "v0.insert(v0.begin(), v0_base.begin(), v0_base.end()): ";
            for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        {
            std::vector<int> v0_base(5, 1);
            std::vector<int> v0;
            v0.insert(v0.end(), v0_base.begin(), v0_base.end());
            std::cout << "v0.insert(v0.end(), v0_base.begin(), v0_base.end()): ";
            for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
    }
}

void erase_method_test(void) {
    {
        std::cout << std::endl << "[ERASE METHOD TEST (POSITION)]" << std::endl;
        std::vector<int> v0(5, 1);
        std::cout << "before v0.erase(v0.begin()): ";
        for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        v0.erase(v0.begin());
        std::cout << "after v0.erase(v0.begin()): ";
        for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[ERASE METHOD TEST (FIRST, LAST)]" << std::endl;
        std::vector<int> v0(5, 1);
        std::cout << "before v0.erase(v0.begin(), v0.end()): ";
        for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        v0.erase(v0.begin(), v0.end());
        std::cout << "after v0.erase(v0.begin(), v0.end()): ";
        for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

void push_method_test(void) {
    std::cout << std::endl << "[PUSH METHOD TEST]" << std::endl;
    std::vector<int> v0(5, 1);
    std::cout << "before v0.push_back(99): ";
    for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    v0.push_back(99);
    std::cout << "after v0.push_back(99): ";
    for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void pop_method_test(void) {
    std::cout << std::endl << "[POP METHOD TEST]" << std::endl;
    std::vector<int> v0(5, 1);
    std::cout << "before v0.pop_back(): ";
    for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    v0.pop_back();
    std::cout << "after v0.pop_back(): ";
    for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void resize_method_test(void) {
    std::cout << std::endl << "[RESIZE METHOD TEST]" << std::endl;
    std::vector<int> v0(5, 1);
    std::cout << "before v0.resize(100) size is: " << v0.size() << std::endl;
    v0.resize(100);
    std::cout << "after v0.resize(100) size is: " << v0.size() << std::endl;
}

void swap_method_test(void) {
    std::cout << std::endl << "[SWAP METHOD TEST]" << std::endl;
    std::vector<int> v0_a(5, 1);
    std::vector<int> v0_b(5, 2);
    std::cout << "before v0_a.swap(v0_b):" << std::endl;
    std::cout << "v0_a: ";
    for (std::vector<int>::iterator it = v0_a.begin(); it != v0_a.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "v0_b: ";
    for (std::vector<int>::iterator it = v0_b.begin(); it != v0_b.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    v0_a.swap(v0_b);
    std::cout << "after v0_a.swap(v0_b):" << std::endl;
    std::cout << "v0_a: ";
    for (std::vector<int>::iterator it = v0_a.begin(); it != v0_a.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "v0_b: ";
    for (std::vector<int>::iterator it = v0_b.begin(); it != v0_b.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void comparison_operators_method_test(void) {
    {
        std::cout << std::endl << "[== OPERATOR / v_a(5, 1) / v_b(5, 2)]" << std::endl;
        std::vector<int> v0_a(5, 1);
        std::vector<int> v0_b(5, 2);
        std::cout << "v0_a == v0_b: " << (v0_a == v0_b) << std::endl;
    }

    {
        std::cout << std::endl << "[!= OPERATOR / v_a(5, 1) / v_b(5, 2)]" << std::endl;
        std::vector<int> v0_a(5, 1);
        std::vector<int> v0_b(5, 2);
        std::cout << "v0_a != v0_b: " << (v0_a != v0_b) << std::endl;
    }

    {
        std::cout << std::endl << "[< OPERATOR / v_a(5, 1) / v_b(5, 2)]" << std::endl;
        std::vector<int> v0_a(5, 1);
        std::vector<int> v0_b(5, 2);
        std::cout << "v0_a < v0_b: " << (v0_a < v0_b) << std::endl;
    }

    {
        std::cout << std::endl << "[<= OPERATOR / v_a(5, 1) / v_b(5, 2)]" << std::endl;
        std::vector<int> v0_a(5, 1);
        std::vector<int> v0_b(5, 2);
        std::cout << "v0_a <= v0_b: " << (v0_a <= v0_b) << std::endl;
    }

    {
        std::cout << std::endl << "[> OPERATOR / v_a(5, 1) / v_b(5, 2)]" << std::endl;
        std::vector<int> v0_a(5, 1);
        std::vector<int> v0_b(5, 2);
        std::cout << "v0_a > v0_b: " << (v0_a > v0_b) << std::endl;
    }

    {
        std::cout << std::endl << "[>= OPERATOR / v_a(5, 1) / v_b(5, 2)]" << std::endl;
        std::vector<int> v0_a(5, 1);
        std::vector<int> v0_b(5, 2);
        std::cout << "v0_a >= v0_b: " << (v0_a >= v0_b) << std::endl;
    }
}


int main(void)
{
    default_constructor_test();
    fill_constructor_test();
    range_constructor_test();
    assignment_operator_test();
    access_operator_test();
    at_method_test();
    front_method_test();
    back_method_test();
    data_method_test();
    empty_method_test();
    size_method_test();
    max_size_method();
    capacity_method_test();
    reserve_method_test();
    assign_method_test();
    clear_method_test();
    insert_method_test();
    erase_method_test();
    push_method_test();
    pop_method_test();
    resize_method_test();
    swap_method_test();
    comparison_operators_method_test();
    return (0);
}
