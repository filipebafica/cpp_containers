// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/vector.hpp"
#include "../headers/type_traits.hpp"

int main(void) {
    {
        std::cout << "[DEFAULT CONSTRUCTOR]" << std::endl;
        ft::vector<int> v0;
        ft::vector<float> v1;
        ft::vector<char> v2;
    }

    {
        std::cout << std::endl << "[FILL CONSTRUCTOR]" << std::endl;
        ft::vector<int> v0(1000, 1);
        ft::vector<float> v1(1000, 1.1);
        ft::vector<char> v2(1000, 'a');
    }

    {
        std::cout << std::endl << "[RANGE CONSTRUCTOR]" << std::endl;
        ft::vector<int> v0(1000, 1);
        ft::vector<int> v1(v0.begin(), v0.end());
    }

    {
        std::cout << std::endl << "[ASSIGNMENT OPERATOR]" << std::endl;
        ft::vector<int> v0(1, 1);
        ft::vector<int> v1;
        v1 = v0;
    }

    {
        try {
            std::cout << std::endl << "['[]' OPERATOR v(10, 1)]" << std::endl;
            ft::vector<int> ft_v(10, 1);
            std::vector<int> std_v(10, 1);
            std::cout << "ft_v[5]: " << ft_v[5] << std::endl;
            std::cout << "std_v[5]: " << std_v[5] << std::endl;
        }
        catch(...) {
            std::cout << "* '[]' operator exception *" << std::endl;
        }
    }

    {
        try {
            std::cout << std::endl << "[AT FUNCTION v(10, 1)]" << std::endl;
            ft::vector<int> ft_v(10, 1);
            std::vector<int> std_v(10, 1);
            std::cout << "ft_v.at(5): " << ft_v.at(5) << std::endl;
            std::cout << "std_v.at(5): " << std_v.at(5) << std::endl;
        }
        catch(...) {
            std::cout << "* At function exception *" << std::endl;
        }
    }

    {
        std::cout << std::endl << "[FRONT FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "ft_v.front(): " << ft_v.front() << std::endl;
        std::cout << "std_v.front(): " << std_v.front() << std::endl;
    }

    {
        std::cout << std::endl << "[BACK FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "ft_v.back(): " << ft_v.back() << std::endl;
        std::cout << "std_v.back(): " << std_v.back() << std::endl;
    }

    {
        std::cout << std::endl << "[DATA FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "*ft_v.data(): " << *ft_v.data() << std::endl;
        std::cout << "*std_v.data(): " << *std_v.data() << std::endl;
    }

    {
        std::cout << std::endl << "[DATA FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "*ft_v.data(): " << *ft_v.data() << std::endl;
        std::cout << "*std_v.data(): " << *std_v.data() << std::endl;
    }

    {
        std::cout << std::endl << "[BEGIN FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "*ft_v.begin(): " << *ft_v.begin() << std::endl;
        std::cout << "*std_v.begin(): " << *std_v.begin() << std::endl;
    }

    {
        std::cout << std::endl << "[END FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "*--ft_v.end(): " << *--ft_v.end() << std::endl;
        std::cout << "*--std_v.end(): " << *--std_v.end() << std::endl;
    }

    {
        std::cout << std::endl << "[RBEGIN FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "*ft_v.rbegin(): " << *ft_v.rbegin() << std::endl;
        std::cout << "*std_v.rbegin(): " << *std_v.rbegin() << std::endl;
    }

    {
        std::cout << std::endl << "[REND FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "*--ft_v.rend(): " << *--ft_v.rend() << std::endl;
        std::cout << "*--std_v.rend(): " << *--std_v.rend() << std::endl;
    }

    {
        std::cout << std::endl << "[EMPTY FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "ft_v.empty(): " << ft_v.empty() << std::endl;
        std::cout << "std_v.empty(): " << std_v.empty() << std::endl;
    }

    {
        std::cout << std::endl << "[EMPTY FUNCTION v()]" << std::endl;
        ft::vector<int> ft_v;
        std::vector<int> std_v;
        std::cout << "ft_v.empty(): " << ft_v.empty() << std::endl;
        std::cout << "std_v.empty(): " << std_v.empty() << std::endl;
    }

    {
        std::cout << std::endl << "[SIZE FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "ft_v.size(): " << ft_v.size() << std::endl;
        std::cout << "std_v.size(): " << std_v.size() << std::endl;
    }

    {
        std::cout << std::endl << "[MAX_SIZE FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "ft_v.max_size(): " << ft_v.max_size() << std::endl;
        std::cout << "std_v.max_size(): " << std_v.max_size() << std::endl;
    }

    {
        std::cout << std::endl << "[CAPACITY FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "ft_v.capacity(): " << ft_v.capacity() << std::endl;
        std::cout << "std_v.capacity(): " << std_v.capacity() << std::endl;
    }

    {
        std::cout << std::endl << "[RESERVE FUNCTION]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "before ft_v.reserve(100) capacity is: " << ft_v.capacity() << std::endl;
        std::cout << "before std_v.reserve(100) capacity is: " << std_v.capacity() << std::endl;
        ft_v.reserve(100);
        std_v.reserve(100);
        std::cout << "after ft_v.reserve(100) capacity is: " << ft_v.capacity() << std::endl;
        std::cout << "after std_v.reserve(100) capacity is: " << std_v.capacity() << std::endl;
    }

    {
        std::cout << std::endl << "[ASSIGN FUNCTION (FILL)] " << std::endl;
        ft::vector<int> ft_v;
        std::vector<int> std_v;
        ft_v.assign(5, 1);
        std_v.assign(5, 1);
        std::cout << "ft_v.assign(5, 1): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "std_v.assign(5, 1): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[ASSIGN FUNCTION (RANGE)] " << std::endl;
        ft::vector<int> ft_v0(5, 1);
        ft::vector<int> ft_v1;
        std::vector<int> std_v0(5, 1);
        std::vector<int> std_v1;
        ft_v1.assign(ft_v0.begin(), ft_v0.end());
        std_v1.assign(std_v0.begin(), std_v0.end());
        std::cout << "ft_v.assign(5, 1): ";
        for (ft::vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "std_v.assign(5, 1): ";
        for (std::vector<int>::iterator it = std_v1.begin(); it != std_v1.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[CLEAR FUNCTION v(10, 1)]" << std::endl;
        ft::vector<int> ft_v(10, 1);
        std::vector<int> std_v(10, 1);
        std::cout << "before ft_v.clear() size is: " << ft_v.size() << std::endl;
        std::cout << "before std_v.clear() size is: " << std_v.size() << std::endl;
        ft_v.clear();
        std_v.clear();
        std::cout << "after ft_v.clear() size is: " << ft_v.size() << std::endl;
        std::cout << "after std_v.clear() size is: " << std_v.size() << std::endl;
    }

    {
        std::cout << std::endl << "[INSERT FUNCTION (POSITION, VALUE)]" << std::endl;
        ft::vector<int> ft_v;
        std::vector<int> std_v;
        ft_v.insert(ft_v.begin(), 10);
        std_v.insert(std_v.begin(), 10);
        std::cout << "ft_v.insert(ft_v.begin(), 10): " << *ft_v.begin() << std::endl;
        std::cout << "std_v.insert(ft_v.begin(), 10): " << *std_v.begin() << std::endl;
        ft_v.insert(ft_v.end(), 10);
        std_v.insert(std_v.end(), 10);
        std::cout << "ft_v.insert(ft_v.end(), 10): " << *--ft_v.end() << std::endl;
        std::cout << "std_v.insert(ft_v.end(), 10): " << *--std_v.end() << std::endl;
    }

    {
        std::cout << std::endl << "[INSERT FUNCTION (POSITION, N, VALUE)]" << std::endl;
        {
            ft::vector<int> ft_v;
            std::vector<int> std_v;
            ft_v.insert(ft_v.begin(), 5, 1);
            std_v.insert(std_v.begin(), 5, 1);
            std::cout << "ft_v.insert(ft_v.begin(), 5, 1): ";
            for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << "std_v.insert(std_v.begin(), 5, 1): ";
            for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        {
            ft::vector<int> ft_v;
            std::vector<int> std_v;
            ft_v.insert(ft_v.end(), 5, 1);
            std_v.insert(std_v.end(), 5, 1);
            std::cout << "ft_v.insert(ft_v.end(), 5, 1): ";
            for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << "std_v.insert(std_v.end(), 5, 1): ";
            for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
    }

    {
        std::cout << std::endl << "[INSERT FUNCTION (POSITION, FIRST, LAST)]" << std::endl;
        {
            ft::vector<int> ft_v_base(5, 1);
            std::vector<int> std_v_base(5, 1);
            ft::vector<int> ft_v;
            std::vector<int> std_v;
            ft_v.insert(ft_v.begin(), ft_v_base.begin(), ft_v_base.end());
            std_v.insert(std_v.begin(), std_v_base.begin(), std_v_base.end());
            std::cout << "ft_v.insert(ft_v.begin(), ft_v_base.begin(), ft_v_base.end()): ";
            for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << "std_v.insert(std_v.begin(), std_v_base.begin(), std_v_base.end()): ";
            for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        {
            ft::vector<int> ft_v_base(5, 1);
            std::vector<int> std_v_base(5, 1);
            ft::vector<int> ft_v;
            std::vector<int> std_v;
            ft_v.insert(ft_v.end(), ft_v_base.begin(), ft_v_base.end());
            std_v.insert(std_v.end(), std_v_base.begin(), std_v_base.end());
            std::cout << "ft_v.insert(ft_v.end(), ft_v_base.begin(), ft_v_base.end()): ";
            for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << "std_v.insert(std_v.end(), std_v_base.begin(), std_v_base.end()): ";
            for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
    }

    {
        std::cout << std::endl << "[ERASE FUNCTION (POSITION)]" << std::endl;
        ft::vector<int> ft_v(5, 1);
        std::vector<int> std_v(5, 1);
        std::cout << "before ft_v.erase(ft_v.begin()): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "before std_v.erase(std_v.begin()): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        ft_v.erase(ft_v.begin());
        std_v.erase(std_v.begin());
        std::cout << "after ft_v.erase(ft_v.begin()): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "after std_v.erase(std_v.begin()): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[ERASE FUNCTION (FIRST, LAST)]" << std::endl;
        ft::vector<int> ft_v(5, 1);
        std::vector<int> std_v(5, 1);
        std::cout << "before ft_v.erase(ft_v.begin(), ft_v.end()): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "before std_v.erase(std_v.begin(), std_v.end()): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        ft_v.erase(ft_v.begin(), ft_v.end());
        std_v.erase(std_v.begin(), std_v.end());
        std::cout << "after ft_v.erase(ft_v.begin(), ft_v.end()): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "after std_v.erase(std_v.begin(), std_v.end()): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[PUSH FUNCTION]" << std::endl;
        ft::vector<int> ft_v(5, 1);
        std::vector<int> std_v(5, 1);
        std::cout << "before ft_v.push_back(99): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "before std_v.push_back(99): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        ft_v.push_back(99);
        std_v.push_back(99);
        std::cout << "after ft_v.push_back(99): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "after std_v.push_back(99): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[POP FUNCTION]" << std::endl;
        ft::vector<int> ft_v(5, 1);
        std::vector<int> std_v(5, 1);
        std::cout << "before ft_v.pop_back(): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "before std_v.pop_back(): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        ft_v.pop_back();
        std_v.pop_back();
        std::cout << "after ft_v.pop_back(): ";
        for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "after std_v.pop_back(): ";
        for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "[RESIZE FUNCTION]" << std::endl;
        ft::vector<int> ft_v(5, 1);
        std::vector<int> std_v(5, 1);
        std::cout << "before ft_v.resize(100) size is: " << ft_v.size() << std::endl;
        std::cout << "before std_v.resize(100) size is: " << std_v.size() << std::endl;
        ft_v.resize(100);
        std_v.resize(100);
        std::cout << "after ft_v.resize(100) size is: " << ft_v.size() << std::endl;
        std::cout << "after std_v.resize(100) size is: " << std_v.size() << std::endl;
    }

    {
        std::cout << std::endl << "[SWAP FUNCTION]" << std::endl;
        ft::vector<int> ft_v_a(5, 1);
        ft::vector<int> ft_v_b(5, 2);
        std::vector<int> std_v_a(5, 1);
        std::vector<int> std_v_b(5, 2);
        std::cout << "before ft_v_a.swap(ft_v_b):" << std::endl;
        std::cout << "ft_v_a: ";
        for (ft::vector<int>::iterator it = ft_v_a.begin(); it != ft_v_a.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "ft_v_b: ";
        for (ft::vector<int>::iterator it = ft_v_b.begin(); it != ft_v_b.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "before std_v_a.swap(std_v_b):" << std::endl;
        std::cout << "std_v_a: ";
        for (std::vector<int>::iterator it = std_v_a.begin(); it != std_v_a.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "std_v_b: ";
        for (std::vector<int>::iterator it = std_v_b.begin(); it != std_v_b.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        ft_v_a.swap(ft_v_b);
        std_v_a.swap(std_v_b);
        std::cout << "after ft_v_a.swap(ft_v_b):" << std::endl;
        std::cout << "ft_v_a: ";
        for (ft::vector<int>::iterator it = ft_v_a.begin(); it != ft_v_a.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "ft_v_b: ";
        for (ft::vector<int>::iterator it = ft_v_b.begin(); it != ft_v_b.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "after std_v_a.swap(std_v_b):" << std::endl;
        std::cout << "std_v_a: ";
        for (std::vector<int>::iterator it = std_v_a.begin(); it != std_v_a.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "std_v_b: ";
        for (std::vector<int>::iterator it = std_v_b.begin(); it != std_v_b.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    return (0);
}
