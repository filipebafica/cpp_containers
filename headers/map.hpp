// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_MAP_HPP_
#define CPP_CONTAINERS_HEADERS_MAP_HPP_

#include <functional>
#include <memory>
#include "./pair.hpp"

namespace ft {
template<typename Key, typename T, typename Compare = std::less<Key>,
         typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
 public:
    /******************** MEMBER TYPES ********************/
    typedef Key                                            key_type;
    typedef T                                              mapped_type;
    typedef ft::pair<const Key, T>                         key_type;
};
}  // namespace ft


#endif  // CPP_CONTAINERS_HEADERS_MAP_HPP_
