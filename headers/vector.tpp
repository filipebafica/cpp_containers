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
    pointer curr = this->memory_impl.memory_start;
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
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc>& src) : vector_base<T, Alloc>(src.size(), src.get_allocator()) {
    std::cout << "Vector copy constructor called" << std::endl;
    pointer curr = this->memory_impl.memory_start;
    const_iterator src_curr = src.begin();
    const_iterator src_end = src.end();
    for (; src_curr != src_end; curr++, src_curr++) {
        this->get_allocator().construct(curr, *src_curr);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + std::distance(src.begin(), src.end());
}

template<class T, class Alloc>
ft::vector<T, Alloc>& ft::vector<T, Alloc>::operator=(const ft::vector<T, Alloc>& rhs) {
    std::cout << "Vector assignment operator vector called" << std::endl;
    if (&rhs == this)
        return (*this);
    const size_type rhs_len = rhs.size();

    // if rhs length is greater than 
    // lhs hold capacity in currently allocated storage
    if (rhs_len > this->capacity()) {
        pointer tmp = this->memory_allocate_and_copy(rhs_len, rhs.begin(), rhs.end());
        std::_Destroy(this->begin(), this->end(), this->get_allocator());
        this->memory_deallocate(this->memory_impl.memory_end_of_storage - this->memory_impl.memory_start);
        this->memory_impl.memory_start = tmp;
        this->memory_impl.memory_end_of_storage = this->memory_impl.memory_start + rhs_len;
    }
    // if lhs number of elements is greater or equal than 
    // rhs hold capacity in currently allocated storage
    else if (this->size() >= rhs_len) {
        iterator i(std::copy(rhs.begin(), rhs.end(), this->begin()));
        std::_Destroy(i, this->end(), this->get_allocator());
    } 
    // if rhs length is less than 
    // lhs hold capacity in currently allocated storage
    else {
        // will copy from rhs the lhs number of elements into lhs
        std::copy(rhs.begin(), rhs.begin() + this->size(), this->memory_impl.memory_start);
        // will construct the remaining elements from rhs into lhs
        pointer lhs_curr = this->memory_impl.memory_start;
        iterator rhs_curr = rhs.begin() + this->size();
        iterator rhs_end = rhs.end();
        for (; rhs_curr != rhs_end; lhs_curr++, rhs_curr++) {
            this->get_allocator().construct(lhs_curr, *rhs_curr);
        }
        this->memory_impl.memory_finish = this->memory_impl.memory_start + rhs_len;
    }
    return (*this);
}


/************************************* DESTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::~vector(void) {
    std::cout << "Vector default destructor called" << std::endl;
    pointer curr = this->memory_impl.memory_start;
    pointer last = this->memory_impl.memory_end_of_storage;
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

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity(void) const {
    return (typename ft::vector<T, Alloc>::size_type(
        this->memory_impl.memory_end_of_storage - this->begin())
    );
}

template<class T, class Alloc>
bool ft::vector<T, Alloc>::empty(void) const {
    return (begin() == end());
}

/************************************* PRIVATE MEMBER FUCNTIONS *************************************/
template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_initialize(iterator first, iterator last, std::input_iterator_tag) {
    for (; first != last; ++first) {
        this->push_back(*first);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_initialize(iterator first, iterator last, std::forward_iterator_tag) {
    const size_type n = std::distance(first, last);
    pointer curr = this->memory_impl.memory_start;
    for (int i = n; i > 0; i--, curr++, first++) {
        this->get_allocator().construct(curr, *first);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + n;
}

/************************************* PROTECTED MEMBER FUCNTIONS *************************************/
template<class T, class Alloc>
typename ft::vector<T, Alloc>::pointer ft::vector<T, Alloc>::memory_allocate_and_copy(size_type n,
    iterator first, iterator last) {
        pointer result = this->memory_allocate(n);
        for (; first != last; result++, first++) {
            this->get_allocator().construct(result, *first);
        }
        return (result - n);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::pointer ft::vector<T, Alloc>::memory_allocate_and_copy(size_type n,
    const_iterator first, const_iterator last) {
        pointer result = this->memory_allocate(n);
        for (; first != last; result++, first++) {
            this->get_allocator().construct(result, *first);
        }
        return (result - n);
}

/************************************* NON-MEMBER OPERATORS OVERLOAD *************************************/
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
