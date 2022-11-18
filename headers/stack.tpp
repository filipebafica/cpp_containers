// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "./stack.hpp"

/************************************* CONSTRUCTORS *************************************/
template<class T, class Alloc>
ft::stack<T, Alloc>::stack(const container_type& c) : c(c){}


/******************** DESTRUCTORS ********************/
template<class T, class Alloc>
ft::stack<T, Alloc>::~stack(void) {}

/******************** MEMBER FUNCTIONS ********************/
// element access
template<class T, class Alloc>
typename ft::stack<T, Alloc>::value_type& ft::stack<T, Alloc>::top(void) {
    return (this->c.back());
}

template<class T, class Alloc>
const typename ft::stack<T, Alloc>::value_type& ft::stack<T, Alloc>::top(void) const {
    return (this->c.back());
}

// capacity
template<class T, class Alloc>
bool ft::stack<T, Alloc>::empty(void) const {
    return (this->c.empty());
}

template<class T, class Alloc>
typename ft::stack<T, Alloc>::size_type ft::stack<T, Alloc>::size(void) const {
    return (this->c.size());
}

// modifiers
template<class T, class Alloc>
void ft::stack<T, Alloc>::push(const value_type& value) {
    this->c.push_back(value);
}

template<class T, class Alloc>
void ft::stack<T, Alloc>::pop(void) {
    if (!this->empty())
        this->c.pop_back();
}