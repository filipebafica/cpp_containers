// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <functional>
#include <map>
#include <iomanip>
#include <iostream>
#include "../headers/map.hpp"

void swap_method_test(void)
{
    std::cout << std::endl << "[SWAP METHOD TEST]" << std::endl;
    ft::map<int, int> x;
    ft::map<int, int> y;

    for (int i = 0; i < 10; i++)
    {
        x.insert(ft::pair<int, int>(i, i));
    }

    for (int i = 100; i < 105; i++)
    {
        y.insert(ft::pair<int, int>(i, i));
    }

    std::cout << "size of x before swap(): " << x.size() << std::endl
              << "size of y before swap(): " << y.size() << std::endl;

    x.swap(y);

    std::cout << "size of x after swap(): " << x.size() << std::endl
            << "size of y after swap(): " << y.size() << std::endl;
}

void equal_range_method_test(void)
{
    std::cout << std::endl << "[EQUAL RANGE METHOD TEST]" << std::endl;
    ft::map<int, int> m;

    m.insert(ft::pair<int, int>(10, 10));
    m.insert(ft::pair<int, int>(20, 20));
    m.insert(ft::pair<int, int>(30, 30));

    ft::pair<typename ft::map<int, int>::iterator, typename ft::map<int, int>::iterator> p = m.equal_range(20);

    std::cout << (*p.first).first << std::endl
              << (*p.second).first << std::endl;
}

void lower_upper_bound_method_test(void)
{
    std::cout << std::endl << "[LOWER BOUND METHOD TEST]" << std::endl;
    {
        ft::map<int, int> map_1;
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "lower_bound(5): " << (*map_1.lower_bound(5)).first << std::endl;
    }
    {
        ft::map<int, int> map_1;
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "upper_bound(5): " << (*map_1.upper_bound(5)).first << std::endl;
    }
}

void count_method_test(void)
{
    std::cout << std::endl << "[COUNT METHOD TEST]" << std::endl;
    {
        ft::map<int, int> map_1;
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "count for 5: " << map_1.count(5) << std::endl;
    }
}

void find_method_test(void)
{
    std::cout << std::endl << "[FIND METHOD TEST]" << std::endl;
    {
        ft::map<int, int> map_1;
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "search for 5: " << (*map_1.find(5)).first << std::endl;
    }
}

void erase_methods_test(void)
{
    std::cout << std::endl << "[ERASE METHODS TEST]" << std::endl;
    ft::map<int, int> map_1;
    {
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << "erase(iterator position)" << std::endl
                  << "before: " << std::endl
                  << "size(): " << map_1.size() << std::endl;

        map_1.erase(map_1.begin());

        std::cout << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;
    }
    {
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << std::endl << "erase(iterator first, iterator last)" << std::endl
                  << "before:" << std::endl
                  << "size(): " << map_1.size() << std::endl;

        map_1.erase(map_1.begin(), map_1.end());

        std::cout << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;
    }
    {
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << std::endl << "erase(const key_type& k)" << std::endl
                  << "before erasing key 5:" << std::endl
                  << "size(): " << map_1.size() << std::endl
                  << "number of elements erased: " << map_1.erase(5) << std::endl
                  << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;

        std::cout << std::endl << "erase(const key_type& k)" << std::endl
                  << "before erasing key 99:" << std::endl
                  << "size(): " << map_1.size() << std::endl
                  << "number of elements erased: " << map_1.erase(99) << std::endl
                  << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;
    }
    {
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << std::endl << "clear(void)" << std::endl
                  << "before:" << std::endl
                  << "size(): " << map_1.size() << std::endl;

        map_1.clear();

        std::cout << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;
    }
}

void capacity_methods_test(void)
{
    std::cout << std::endl << "[CAPACITY METHODS TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << map_1.empty() << std::endl;
    std::cout << map_1.size() << std::endl;
    std::cout << (map_1.max_size() != 0) << std::endl;
}

void end_method_test(void)
{
    std::cout << std::endl << "[END METHOD TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    const ft::map<int, int> map_2(map_1.begin(), map_1.end());

    std::cout << (*--map_2.end()).first << std::endl;
    std::cout << (*--map_1.end()).first << std::endl;
}

void begin_method_test(void)
{
    std::cout << std::endl << "[BEGIN METHOD TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    const ft::map<int, int> map_2(map_1.begin(), map_1.end());

    std::cout << (*map_2.begin()).first << std::endl;
    std::cout << (*map_1.begin()).first << std::endl;
}

void at_method_test(void)
{
    std::cout << std::endl << "[AT METHOD TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << map_1.at(0) << std::endl;
    std::cout << map_1.at(5) << std::endl;

    try {
        map_1.at(100);
    }
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
}

void access_operator_test(void)
{
    std::cout << std::endl << "[ACCESS OPERATOR TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    std::cout << map_1[0] << std::endl;
    std::cout << map_1[5] << std::endl;
    std::cout << map_1[100] << std::endl;
}

void insert_method_test(void)
{
    std::cout << std::endl << "[INSERT METHOD TEST]" << std::endl;
    {
        ft::map<int, int> map_1;
        std::cout << "insert(const value_type& value)" << std::endl
                  << "before:" << std::endl
                  << "size(): " << map_1.size() << std::endl;

        map_1.insert(ft::pair<int, int>(10, 10));

        std::cout << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;
    }

    {
        ft::map<int, int> map_1;
        std::cout << std::endl << "insert(iterator position, const value_type& value)" << std::endl
                  << "before:" << std::endl
                  << "size(): " << map_1.size() << std::endl;

        map_1.insert(map_1.begin(), ft::pair<int, int>(10, 10));

        std::cout << "after:" << std::endl
                  << "size(): " << map_1.size() << std::endl;
    }

    {
        ft::map<int, int> map_1;
        ft::map<int, int> map_2;
        for (int i = 0; i < 10; i++)
        {
            map_1.insert(ft::pair<int, int>(i, i));
        }

        std::cout << std::endl << "insert(iterator first, iterator last)" << std::endl
                  << "before:" << std::endl
                  << "size(): " << map_2.size() << std::endl;

        map_2.insert(map_1.begin(), map_1.end());

        std::cout << "after:" << std::endl
                  << "size(): " << map_2.size() << std::endl;
    }
}

void assignment_operator_test(void)
{
    std::cout << std::endl << "[ASSIGNMENT OPERATOR TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> map_2 = map_1;
    std::cout << "size of map_1: " << map_1.size() << std::endl
              << "size of map_2: " << map_2.size() << std::endl;
}

void copy_constructor_test(void)
{
    std::cout << std::endl << "[COPY CONSTRUCTOR TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> map_2(map_1);
    std::cout << "size of map_1: " << map_1.size() << std::endl
              << "size of map_2: " << map_2.size() << std::endl;
}

void range_constructor_test(void)
{
    std::cout << "[RANGE CONSTRUCTOR TEST]" << std::endl;
    ft::map<int, int> map_1;

    for (int i = 0; i < 10; i++)
    {
        map_1.insert(ft::pair<int, int>(i, i));
    }

    ft::map<int, int> map_2(map_1.begin(), map_1.end());
    std::cout << "size of map_1: " << map_1.size() << std::endl
              << "size of map_2: " << map_2.size() << std::endl;
}

int main(void)
{
    range_constructor_test();
    copy_constructor_test();
    assignment_operator_test();
    insert_method_test();
    access_operator_test();
    at_method_test();
    begin_method_test();
    end_method_test();
    capacity_methods_test();
    erase_methods_test();
    find_method_test();
    count_method_test();
    lower_upper_bound_method_test();
    equal_range_method_test();
    swap_method_test();
    return (0);
}
