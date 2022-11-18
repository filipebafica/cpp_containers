// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <ctime>
#include <vector>
#include <iostream>

int main(void) {
    clock_t t;
    int     num_elements;

    t = std::clock();
    num_elements = 100000;
    {
        std::cout << "[TESTING INSERTION (BEGIN)]" << std::endl;
        std::vector<int> std_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            std_v.insert(std_v.begin(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (MIDLLE)]" << std::endl;
        std::vector<int> std_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            std_v.insert(std_v.begin() + (num_elements / 2), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (END)]" << std::endl;
        std::vector<int> std_v(num_elements, 1);
        for (int i = 0; i < num_elements; i++)
            std_v.insert(std_v.end(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING SWAP]" << std::endl;
        std::vector<int> std_v_a(num_elements, 1);
        std::vector<int> std_v_b(num_elements, 0);
        std_v_a.swap(std_v_b);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING ERASE]" << std::endl;
        std::vector<int> std_v(num_elements, 1);
        std_v.erase(std_v.begin(), std_v.end());
        std::cout << "STATUS: OK" << std::endl;
    }
    t = clock() - t;

    std::cout << "Time taken by test is: "
              << static_cast<float>(t) / CLOCKS_PER_SEC
              << std::endl;
    return (0);
}
