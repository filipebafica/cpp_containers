// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <ctime>
#include <vector>
#include <iostream>

int main(void) {
    clock_t t;

    t = std::clock();
    {
        std::cout << "[TESTING INSERTION (BEGIN)]" << std::endl;
        std::vector<int> std_v(100000, 1);
        for (int i = 0; i < 100000; i++)
            std_v.insert(std_v.begin(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (MIDLLE)]" << std::endl;
        std::vector<int> std_v(100000, 1);
        for (int i = 0; i < 100000; i++)
            std_v.insert(std_v.begin() + 50000, i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING INSERTION (END)]" << std::endl;
        std::vector<int> std_v(100000, 1);
        for (int i = 0; i < 100000; i++)
            std_v.insert(std_v.end(), i);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING SWAP]" << std::endl;
        std::vector<int> std_v_a(100000, 1);
        std::vector<int> std_v_b(100000, 0);
        std_v_a.swap(std_v_b);
        std::cout << "STATUS: OK" << std::endl;
    }
    {
        std::cout << "[TESTING ERASE]" << std::endl;
        std::vector<int> std_v(100000, 1);
        std_v.erase(std_v.begin(), std_v.end());
        std::cout << "STATUS: OK" << std::endl;
    }
    t = clock() - t;

    std::cout << "Time taken by test is: "
              << static_cast<float>(t) / CLOCKS_PER_SEC
              << std::endl;
    return (0);
}
