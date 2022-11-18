// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_STACK_HPP_
#define CPP_CONTAINERS_HEADERS_STACK_HPP_


#include "./vector.hpp"

namespace ft {
template<class T, class Alloc = ft::vector<T> >
class stack {

 public:
    /******************** MEMBER TYPES ********************/
    typedef typename Alloc::value_type           value_type;
    typedef typename Alloc::size_type            size_type;
    typedef          Alloc                       container_type;

    /******************** CONSTRUCTORS ********************/
    explicit stack(const container_type& c = container_type());
    stack& operator=(stack const& rhs);

    /******************** DESTRUCTORS ********************/
    ~stack(void);

 public:
    /******************** MEMBER FUNCTIONS ********************/
    // element access
    value_type& top(void);
    const value_type& top(void) const;

    // capacity
    bool empty(void) const;
    size_type size(void) const;

    // modifiers
    void push(const value_type& value);
    void pop(void);

 protected:
    container_type c;

};

template<class T, class Alloc>
bool operator==(const stack<T, Alloc>& lhs,
                const stack<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator!=(const stack<T, Alloc>& lhs,
                const stack<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator<(const stack<T, Alloc>& lhs,
                const stack<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator<=(const stack<T, Alloc>& lhs,
                const stack<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator>(const stack<T, Alloc>& lhs,
                const stack<T, Alloc>& rhs);

template<class T, class Alloc>
bool operator>=(const stack<T, Alloc>& lhs,
                const stack<T, Alloc>& rhs);

}  // namespace ft

#include "./stack.tpp"

#endif  // CPP_CONTAINERS_HEADERS_STACK_HPP_