// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "../headers/red_black_tree.hpp"

int main(void) {
    ft::red_black_tree<int> rb;

    rb.insert_node(11);
    rb.insert_node(2);
    rb.insert_node(14);
    rb.insert_node(1);
    rb.insert_node(15);
    rb.insert_node(7);
    rb.insert_node(5);
    rb.insert_node(8);
    rb.insert_node(4);
    rb.print_tree_debug();

    std::cout << std::endl;
    rb.delete_node(2);
    rb.print_tree_debug();
    return (0);
}
