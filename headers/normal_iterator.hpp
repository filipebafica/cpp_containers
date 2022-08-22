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
    typedef typename ft::iteratorTraits<Iterator>::iterator_category    iterator_category;
    typedef typename ft::iteratorTraits<Iterator>::value_type           value_type;
    typedef typename ft::iteratorTraits<Iterator>::difference_type      difference_type;
    typedef typename ft::iteratorTraits<Iterator>::reference            reference;
    typedef typename ft::iteratorTraits<Iterator>::pointer              pointer;

    NormalIterator(void);
    explicit NormalIterator(const Iterator& i);

    reference operator*(void) const;
    pointer operator->(void) const;
    NormalIterator& operator++(void);
    NormalIterator operator++(int);
    NormalIterator& operator--(void);
    NormalIterator operator--(int);
    reference operator[](const difference_type& n) const;
    NormalIterator& operator+=(const difference_type& n);
    NormalIterator& operator-=(const difference_type& n);
    NormalIterator operator+(const difference_type& n) const;
    NormalIterator operator-(const difference_type& n) const;

    const Iterator& base(void) const;
};

template<typename IteratorL, typename IteratorR, typename Container>
bool operator==(const NormalIterator<IteratorL, Container>& lhs,
                const NormalIterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator==(const NormalIterator<Iterator, Container>& lhs,
                const NormalIterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator!=(const NormalIterator<IteratorL, Container>& lhs,
                const NormalIterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator!=(const NormalIterator<Iterator, Container>& lhs,
                const NormalIterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<(const NormalIterator<IteratorL, Container>& lhs,
                const NormalIterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator<(const NormalIterator<Iterator, Container>& lhs,
                const NormalIterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>(const NormalIterator<IteratorL, Container>& lhs,
                const NormalIterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator>(const NormalIterator<Iterator, Container>& lhs,
                const NormalIterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<=(const NormalIterator<IteratorL, Container>& lhs,
                const NormalIterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator<=(const NormalIterator<Iterator, Container>& lhs,
                const NormalIterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>=(const NormalIterator<IteratorL, Container>& lhs,
                const NormalIterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator>=(const NormalIterator<Iterator, Container>& lhs,
                const NormalIterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::NormalIterator<IteratorL, Container>::difference_type operator-(
    const ft::NormalIterator<IteratorL, Container>& lhs,
    const ft::NormalIterator<IteratorR, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::NormalIterator<IteratorL, Container>::difference_type operator+(
    typename ft::NormalIterator<IteratorL, Container>::difference_type n,
    const ft::NormalIterator<IteratorR, Container>& i);

}  // namespace ft

#include "./normal_iterator.tpp"

#endif  // CPP_CONTAINERS_HEADERS_ITERATOR_HPP_
