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
        std::cout << "*--ft_v.end(): " << *--ft_v.rend() << std::endl;
        std::cout << "*--std_v.end(): " << *--std_v.rend() << std::endl;
    }
    return (0);
}
