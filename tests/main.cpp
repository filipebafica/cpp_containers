#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include "../headers/vector.hpp"
#include "../headers/map.hpp"
#include "../headers/stack.hpp"



void ft_basic_test(void) {
    clock_t start, end;
    int     num_elements;

    start = clock();
    num_elements = 100000;
    {
        std::cout << "[FT VECTOR BASIC TEST]" << std::endl;
        ft::vector<int> ft_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            ft_v.insert(ft_v.begin(), i);
        std::cout << "STATUS: OK" << std::endl;
    }

    {
        std::cout << "[FT MAP BASIC TEST" << std::endl;
        ft::map<int, int> m;
        for (int i = 0; i < num_elements; i++)
            m.insert(ft::pair<int, int>(i, i));
        std::cout << "STATUS: OK" << std::endl;
    }

    {
        std::cout << "[FT MAP BASIC TEST]" << std::endl;
        ft::stack<int> s;
        for (int i = 0; i < num_elements; i++)
            s.push(i);
        std::cout << "STATUS: OK" << std::endl;
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by test is: " << std::fixed
              << time_taken << std::setprecision(5)
              << std::endl << std::endl;
}

void std_basic_test(void) {
    clock_t start, end;
    int     num_elements;

    start = clock();
    num_elements = 100000;
    {
        std::cout << "[STD VECTOR BASIC TEST]" << std::endl;
        std::vector<int> std_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            std_v.insert(std_v.begin(), i);
        std::cout << "STATUS: OK" << std::endl;
    }

    {
        std::cout << "[STD MAP BASIC TEST" << std::endl;
        std::map<int, int> m;
        for (int i = 0; i < num_elements; i++)
            m.insert(std::pair<int, int>(i, i));
        std::cout << "STATUS: OK" << std::endl;
    }

    {
        std::cout << "[STD MAP BASIC TEST]" << std::endl;
        std::stack<int> s;
        for (int i = 0; i < num_elements; i++)
            s.push(i);
        std::cout << "STATUS: OK" << std::endl;
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by test is: " << std::fixed
              << time_taken << std::setprecision(5)
              << std::endl << std::endl;
}


int main(void) {
    ft_basic_test();
    std_basic_test();
    return (0);
}
