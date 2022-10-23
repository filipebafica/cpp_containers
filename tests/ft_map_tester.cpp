// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <functional>
#include <map>
#include "../headers/map.hpp"

int main(void) {
    ft::map<char, int> m;

    m.insert(ft::pair<char, int>('a', 1));
    return (0);
}
