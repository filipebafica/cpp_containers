// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector.hpp"

/************************************* CONSTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : vector_base<T, Alloc>(alloc) {
    std::cout << "Empty vector constructor called" << std::endl;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) : vector_base<T, Alloc>(n, alloc) {
    std::cout << "Fill vector constructor called" << std::endl;
    T* curr = this->memory_impl.memory_start;
    for (size_type i = n; i > 0; i--, curr++) {
        this->get_allocator().construct(curr, value);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc) : vector_base<T, Alloc>(std::distance(first, last), alloc) {
    std::cout << "Range vector constructor called" << std::endl;
    typedef typename ft::iterator_traits<iterator>::iterator_category iterator_category;
    this->memory_range_initialize(first, last, iterator_category());
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_initialize(iterator first, iterator last, std::input_iterator_tag) {
    for (; first != last; ++first) {
        this->push_back(*first);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_initialize(iterator first, iterator last, std::forward_iterator_tag) {
    const size_type n = std::distance(first, last);
    T* curr = this->memory_impl.memory_start;
    for (int i = n; i > 0; i--, curr++, first++) {
        this->get_allocator().construct(curr, *first);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc>& src) : vector_base<T, Alloc>(src.size(), src.get_allocator()) {
    std::cout << "Copy vector constructor called" << std::endl;
}


/************************************* DESTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::~vector(void) {
    std::cout << "Default vector destructor called" << std::endl;
    T* curr = this->memory_impl.memory_start;
    T* last = this->memory_impl.memory_end_of_storage;
    for (; curr != last; curr++) {
        this->get_allocator().destroy(this->memory_impl.memory_start);
    }
}

/************************************* MEMBER FUNCTIONS *************************************/
// iterators
template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin(void) {
    return (iterator(this->memory_impl.memory_start));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end(void) {
    return (iterator(this->memory_impl.memory_finish));
}

