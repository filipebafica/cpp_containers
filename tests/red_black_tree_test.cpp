// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "../headers/red_black_tree.hpp"

int main(void) {
    ft::red_black_tree<int> rb;

    rb.insert(1);
    rb.insert(9);
    rb.insert(10);
    rb.insert(2);
    rb.print_tree_debug();
    return (0);
}
