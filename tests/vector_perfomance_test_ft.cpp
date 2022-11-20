// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <ctime>
#include "../headers/vector.hpp"

int main(void) {
    clock_t t;
    int     num_elements;

    t = std::clock();
    num_elements = 100000;
    {
        std::cout << "[TESTING INSERTION (BEGIN)]" << std::endl;
        ft::vector<int> ft_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            ft_v.insert(ft_v.begin(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (MIDLLE)]" << std::endl;
        ft::vector<int> ft_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            ft_v.insert(ft_v.begin() + (num_elements / 2), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (END)]" << std::endl;
        ft::vector<int> ft_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            ft_v.insert(ft_v.end(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING SWAP]" << std::endl;
        ft::vector<int> ft_v_a(num_elements, 1);
        ft::vector<int> ft_v_b(num_elements, 0);
        ft_v_a.swap(ft_v_b);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING ERASE]" << std::endl;
        ft::vector<int> ft_v(num_elements, 1);
        ft_v.erase(ft_v.begin(), ft_v.end());
        std::cout << "STATUS: OK" << std::endl;
    }
    t = clock() - t;

    std::cout << "Time taken by test is: "
              << static_cast<float>(t) / CLOCKS_PER_SEC
              << std::endl;
    return (0);
}
