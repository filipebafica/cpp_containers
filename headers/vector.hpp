// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_VECTOR_HPP_
#define CPP_CONTAINERS_HEADERS_VECTOR_HPP_

#include <memory>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include "./vector_base.hpp"
#include "./normal_iterator.hpp"
#include "./iterator_traits.hpp"
#include "./type_traits.hpp"

namespace ft {
template<class T, class Alloc = std::allocator<T> >
class vector : protected vector_base<T, Alloc> {
 public:
    /******************** MEMBER TYPES ********************/
    typedef T                                           value_type;
    typedef Alloc                                       allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef normal_iterator<pointer, vector>            iterator;
    typedef normal_iterator<const_pointer, vector>      const_iterator;
    // typedef reverse_iterator;
    // typedef const_reverse_iterator;
    // typedef difference_type;
    typedef size_t size_type;

    /******************** CONSTRUCTORS ********************/
    explicit vector(const allocator_type& alloc = allocator_type());
    explicit vector(size_type n,
                 const value_type& value = value_type(),
                 const allocator_type& alloc = allocator_type());
    vector(iterator first, iterator last,
                 const allocator_type& alloc = allocator_type());
    vector(const vector& src);
    vector& operator=(vector const& rhs);
    allocator_type get_allocator(void) const;


    /******************** DESTRUCTORS ********************/
    ~vector(void);

    /******************** MEMBER FUNCTIONS ********************/
    // element access
    reference at(size_type n);
    const_reference at(size_type n) const;
    reference operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference front(void);
    const_reference front(void) const;
    reference back(void);
    const_reference back(void) const;
    value_type* data(void);
    const value_type* data() const;

    // // iterators
    iterator begin(void);
    const_iterator begin(void) const;
    iterator end(void);
    const_iterator end(void) const;
    // reverse_iterator rbegin(void);
    // const_reverse_iterator rbegin(void) const;
    // reverse_iterator rend(void);
    // const_reverse_iterator rend(void) const;

    // // capacity
    bool empty(void) const;
    size_type size(void) const;
    size_type max_size(void) const;
    void reserve(size_type n);
    size_type capacity(void) const;

    // modifiers
    void assign(size_type n, const value_type& value);
    void assign(iterator first, iterator last);
    void clear(void);
    iterator insert(iterator position, const value_type& value);
    void insert(iterator position, size_type n, const value_type& value);
    void insert(iterator position, iterator first, iterator last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void push_back(const value_type& value);
    void pop_back(void);
    void resize(size_type n, value_type value = value_type());
    void swap(vector& x);

 private:
    /******************** MEMBER FUNCTIONS ********************/
    void unitialized_fill_n_a(pointer memory_start, size_type n,
                    const value_type& value);
    void unitialized_copy_a(iterator first, iterator last,
                    pointer memory_start);
    void unitialized_copy_a(const_iterator first, const_iterator last,
                    pointer memory_start);
    iterator unitialized_copy_a(iterator first, iterator last,
                    iterator result);
    void destroy(value_type* p);
    void destroy(pointer memory_start, pointer memory_finish);
    void destroy(iterator first, iterator last);

 protected:
    void memory_range_initialize(iterator first, iterator last,
                    std::input_iterator_tag);
    void memory_range_initialize(iterator first, iterator last,
                    std::forward_iterator_tag);
    void memory_range_insert(iterator position, iterator first, iterator last,
                    std::input_iterator_tag);
    pointer memory_allocate_and_copy(size_type n, iterator first,
                    iterator last);
    pointer memory_allocate_and_copy(size_type n, const_iterator first,
                    const_iterator last);
    void memory_fill_assign(size_type n, const value_type& value);
    void memory_assign_aux(iterator first, iterator last,
                    std::input_iterator_tag);
    void memory_fill_insert(iterator position, size_type n,
                    const value_type& value);
    void memory_insert_aux(iterator position, const value_type& value);
};

template<class T, class Alloc>
bool operator==(const vector<T, Alloc>& lhs,
                const vector<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator!=(const vector<T, Alloc>& lhs,
                const vector<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator<(const vector<T, Alloc>& lhs,
                const vector<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator<=(const vector<T, Alloc>& lhs,
                const vector<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator>(const vector<T, Alloc>& lhs,
                const vector<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator>=(const vector<T, Alloc>& lhs,
                const vector<T, Alloc>& rhs);

template<class T, class Alloc>
bool swap(const vector<T, Alloc>& x,
            const vector<T, Alloc>& y);
}  // namespace ft

#include "./vector.tpp"

#endif  // CPP_CONTAINERS_HEADERS_VECTOR_HPP_
