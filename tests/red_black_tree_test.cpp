// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <cstdlib>
#include "../headers/red_black_tree.hpp"
#include "../headers/vector.hpp"

int num_elemet = 1000000;
int max_del = num_elemet - 10;
ft::vector<int> base_elements;
ft::red_black_tree<int> rb;

void delete_test(void) {
    for (int i = 0; i < max_del; i++) {
        rb.delete_node(base_elements[i]);
    }
}

void insert_test(void) {
    for (int i = 0; i < num_elemet; i++) {
        rb.insert_node(base_elements[i]);
    }
}

int main(void) {
    base_elements.reserve(num_elemet);
    srand(42);
    for (int i = 0; i < num_elemet; i++) {
        base_elements.insert(base_elements.end(), (std::rand() % (num_elemet * 1000) + 1));
    }

    insert_test();

    rb.print_tree_debug();

    delete_test();

    rb.print_tree_debug();

    return (0);
}
