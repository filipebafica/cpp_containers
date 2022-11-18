// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "../headers/vector.hpp"
#include "../headers/type_traits.hpp"

template<typename T>
struct is_type_container {
    static const bool value = false;
};

template<typename T>
struct is_type_container<ft::vector<T> > {
    static const bool value = true;
};

template<typename T>
void p(T x, typename ft::enable_if<is_type_container<T>::value, T>::type* = NULL) {
    std::cout << "it's a ft_vector" << std::endl;
    (void)x;
}

template<typename T>
void p(T x, typename ft::enable_if<!is_type_container<T>::value, T>::type* = NULL) {
    std::cout << "it's not a ft_vector" << std::endl;
    (void)x;
}

int main(void) {
    ft::vector<int> ft_v;
    int             my_int = 1;
    char            my_char = 'a';
    char            my_float = 1.f;
    p(ft_v);
    p(my_int);
    p(my_char);
    p(my_float);
    return (0);
}
