// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <ctime>
#include <map>
#include "../headers/map.hpp"

int main(void) {
    clock_t t;
    int     num_elements;

    t = std::clock();
    num_elements = 1000000;
    {
        std::cout << "[TESTING INSERTION]" << std::endl;
        std::map<int, int> m;
        for (int i = 0; i < num_elements; i++)
            m.insert(std::pair<int, int>(i, i));
    }
    t = clock() - t;

    std::cout << "Time taken by test is: "
              << static_cast<float>(t) / CLOCKS_PER_SEC
              << std::endl;
    return (0);
}
