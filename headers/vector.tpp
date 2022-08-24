// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector.hpp"

/************************************* CONSTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : vector_base<T, Alloc>(alloc) {
    std::cout << "Vector empty constructor called" << std::endl;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) : vector_base<T, Alloc>(n, alloc) {
    std::cout << "Vector fill constructor called" << std::endl;
    T* curr = this->memory_impl.memory_start;
    for (size_type i = n; i > 0; i--, curr++) {
        this->get_allocator().construct(curr, value);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc) : vector_base<T, Alloc>(std::distance(first, last), alloc) {
    std::cout << "Vector range constructor called" << std::endl;
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
    std::cout << "Vector copy constructor called" << std::endl;
    T* curr = this->memory_impl.memory_start;
    typename ft::vector<T, Alloc>::const_iterator src_curr = src.begin();
    typename ft::vector<T, Alloc>::const_iterator src_end = src.end();
    for (; src_curr != src_end; curr++, src_curr++) {
        this->get_allocator().construct(curr, *src_curr);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + std::distance(src.begin(), src.end());
}

template<class T, class Alloc>
ft::vector<T, Alloc>& ft::vector<T, Alloc>::operator=(const ft::vector<T, Alloc>& rhs) {
    std::cout << "Vector assignment operator vector called" << std::endl;
}


/************************************* DESTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::~vector(void) {
    std::cout << "Vector default destructor called" << std::endl;
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
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin(void) const {
    return (const_iterator(this->memory_impl.memory_start));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end(void) {
    return (iterator(this->memory_impl.memory_finish));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end(void) const {
    return (const_iterator(this->memory_impl.memory_finish));
}

// capacity
template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size(void) const {
    return (typename ft::vector<T, Alloc>::size_type(this->end() - this->begin()));
}

/************************************* OPERATORS OVERLOAD *************************************/
template<class T, class Alloc>
bool ft::operator==(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return (
            lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin())
        );
}

template<class T, class Alloc>
bool ft::operator<(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return (std::lexicographical_compare(
            lhs.begin(), lhs.end(), rhs.begin(), rhs.end()
        ));
}

template<class T, class Alloc>
bool ft::operator!=(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return !(lhs == rhs);
}

template<class T, class Alloc>
bool ft::operator>(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return (rhs < lhs);
}

template<class T, class Alloc>
bool ft::operator<=(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return !(rhs < lhs);
}

template<class T, class Alloc>
bool ft::operator>=(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return !(lhs < rhs);
}
