// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_ITERATOR_HPP_
#define CPP_CONTAINERS_HEADERS_ITERATOR_HPP_

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct foward_iterator_tag : public input_iterator_tag {};
struct biderectinal_iterator_tag : public foward_iterator_tag {};
struct random_access_iterator_tag : public biderectinal_iterator_tag {};

template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
struct iterator {
    typedef _Category   iterator_category;
    typedef _Tp         value_type;
    typedef _Distance   difference_type;
    typedef _Pointer    pointer;
    typedef _Reference  reference;
};
}  // namespace ft

#endif  // CPP_CONTAINERS_HEADERS_ITERATOR_HPP_
