// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <ctime>
#include <vector>
#include "../headers/vector.hpp"

int main(void) {
    clock_t t;

    t = std::clock();
    {
        std::cout << "[TESTING INSERTION (BEGIN)]" << std::endl;
        ft::vector<int> ft_v(100000, 1);
        for (int i = 0; i < 100000; i++)
            ft_v.insert(ft_v.begin(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (MIDLLE)]" << std::endl;
        ft::vector<int> ft_v(100000, 1);
        for (int i = 0; i < 100000; i++)
            ft_v.insert(ft_v.begin() + 50000, i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (END)]" << std::endl;
        ft::vector<int> ft_v(100000, 1);
        for (int i = 0; i < 100000; i++)
            ft_v.insert(ft_v.end(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING SWAP]" << std::endl;
        ft::vector<int> ft_v_a(100000, 1);
        ft::vector<int> ft_v_b(100000, 0);
        ft_v_a.swap(ft_v_b);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING ERASE]" << std::endl;
        ft::vector<int> ft_v(100000, 1);
        ft_v.erase(ft_v.begin(), ft_v.end());
        std::cout << "STATUS: OK" << std::endl;
    }
    t = clock() - t;

    std::cout << "Time taken by test is: "
              << static_cast<float>(t) / CLOCKS_PER_SEC
              << std::endl;
    return (0);
}
