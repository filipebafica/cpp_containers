// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_ITERATOR_HPP_
#define CPP_CONTAINERS_HEADERS_ITERATOR_HPP_
#include "./iterator_traits.hpp"

namespace ft {
template<typename Iterator, typename Container>
class NormalIterator {
 protected:
    Iterator memoryCurrent;
 public:
    typedef typename ft::iteratorTraits<Iterator>::iterator_category iterator_category;
    typedef typename ft::iteratorTraits<Iterator>::value_type value_type;
    typedef typename ft::iteratorTraits<Iterator>::reference reference;
    typedef typename ft::iteratorTraits<Iterator>::pointer pointer;

    NormalIterator(void);
};
}  // namespace ft

#include "./normal_iterator.tpp"

#endif  // CPP_CONTAINERS_HEADERS_ITERATOR_HPP_
