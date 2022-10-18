// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_MAP_HPP_
#define CPP_CONTAINERS_HEADERS_MAP_HPP_

#include <functional>
#include <memory>
#include "./pair.hpp"
#include "./red_black_tree.hpp"

namespace ft {
template<typename Key, typename T, typename Compare = std::less<Key>,
         typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
 public:
    /******************** MEMBER TYPES ********************/
    typedef Key                                            key_type;
    typedef T                                              mapped_type;
    typedef ft::pair<const Key, T>                         value_type;
    typedef Compare                                        key_compare;

    // defines a nested class that will be used to compare keys
    class value_compare {
        friend class map<Key, T, Compare, Alloc>;
     protected:
        Compare comp;
        explicit value_compare(Compare c);

     public:
        bool operator()(const value_type& x, const value_type& y) const;
    };

 private:
    typedef ft::red_black_tree<key_type, value_type,
                                key_compare, Alloc>   RB_type;
    RB_type                                            memory_tree;

 public:
    typedef typename Alloc::pointer                    pointer;
    typedef typename Alloc::const_pointer              const_pointer;
    typedef typename Alloc::reference                  reference;
    typedef typename Alloc::const_reference            const_reference;
    typedef typename RB_type::allocator_type           allocator_type;
    typedef typename RB_type::iterator                 iterator;
    typedef typename RB_type::const_iterator           const_iterator;
    typedef typename RB_type::size_type                size_type;
    typedef typename RB_type::difference_type          difference_type;
    typedef typename RB_type::reverse_iterator         reverse_iterator;
    typedef typename RB_type::const_reverse_iterator   const_reverse_iterator;

    /******************** CONSTRUCTORS ********************/
    map(void);
};
}  // namespace ft

#include "./map.tpp"


#endif  // CPP_CONTAINERS_HEADERS_MAP_HPP_
