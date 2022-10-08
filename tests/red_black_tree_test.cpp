// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "../headers/red_black_tree.hpp"

int main(void) {
    ft::red_black_tree<int> rb;

    rb.insert(11);
    rb.insert(2);
    rb.insert(14);
    rb.insert(1);
    rb.insert(15);
    rb.insert(7);
    rb.insert(5);
    rb.insert(8);
    rb.insert(4);
    rb.print_tree_debug();
    return (0);
}
