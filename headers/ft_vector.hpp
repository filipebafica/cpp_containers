// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_FT_VECTOR_HPP_
#define CPP_CONTAINERS_HEADERS_FT_VECTOR_HPP_

#include <memory>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
class vector {
 public:
    /******************** MEMBER TYPES ********************/
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    // typedef iterator;
    // typedef const_iterator;
    // typedef reverse_iterator;
    // typedef const_reverse_iterator;
    // typedef difference_type;
    // typedef size_type;

    /******************** MEMBER FUNCTIONS ********************/
    vector(void);
    explicit vector(const allocator_type& alloc);
    // explicit vector(size_type count,
    //              const T& value = T(),
    //              const Allocator& alloc = Allocator());
    // template<class InputIt>
    // vector(InputIt first, InputIt last,
    //         const Allocator& alloc = Allocator());
    // vector(const vector& src);
    // ~vector(void);
    // vector& operator=(vector const& rhs);
    // void assign(size_type count, const T& value);
    // template<class InputIt>
    // void assign(InputIt first, InputIt last);
    // allocator_type get_allocator(void) const;

    // // element access
    // reference at(size_type pos);
    // const_reference at(size_type pos) const;
    // reference operator[](size_type pos);
    // const_reference operator[](size_type pos) const;
    // reference front(void);
    // const_reference front(void) const;
    // reference back(void);
    // const_reference back(void) const;
    // T* data(void);
    // const T* data() const;

    // // iterators
    // iterator begin(void);
    // const_iterator begin(void) const;
    // iterator end(void);
    // const_iterator end(void) const;
    // reverse_iterator rbegin(void);
    // const_reverse_iterator rbegin(void) const;
    // reverse_iterator rend(void);
    // const_reverse_iterator rend(void) const;

    // // capacity
    // bool empty(void) const;
    // size_type size(void) const;
    // size_type max_size(void) const;
    // void reserve(size_type new_cap);
    // size_type capacity(void) const;

    // // modifiers
    // void clear(void);
    // iterator insert(iterator pos, const T& value);
    // void insert(iterator pos, size_type count, const T& value);
    // template<class InputIt>
    // void insert(iterator pos, InputIt first, InputIt last);
    // iterator erase(iterator pos);
    // iterator erase(iterator first, iterator last);
    // void push_back(const T& value);
    // void pop_back(void);
    // void resize(size_type count, T value = T());
    // void swap(vector& other);
};

// template<class T, class Alloc>
// bool operator==(const vector<T, Alloc>& lhs,
//                 const vector<T, Alloc>& rhs);

// template<class T, class Alloc>
// bool operator!=(const vector<T, Alloc>& lhs,
//                 const vector<T, Alloc>& rhs);

// template<class T, class Alloc>
// bool operator<(const vector<T, Alloc>& lhs,
//                 const vector<T, Alloc>& rhs);

// template<class T, class Alloc>
// bool operator<=(const vector<T, Alloc>& lhs,
//                 const vector<T, Alloc>& rhs);

// template<class T, class Alloc>
// bool operator>(const vector<T, Alloc>& lhs,
//                 const vector<T, Alloc>& rhs);

// template<class T, class Alloc>
// bool operator>=(const vector<T, Alloc>& lhs,
//                 const vector<T, Alloc>& rhs);
}  // namespace ft

#include "./ft_vector.tpp"

#endif  // CPP_CONTAINERS_HEADERS_vector_HPP_
