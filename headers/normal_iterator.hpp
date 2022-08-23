// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_NORMAL_ITERATOR_HPP_
#define CPP_CONTAINERS_HEADERS_NORMAL_ITERATOR_HPP_
#include "./iterator_traits.hpp"

namespace ft {
template<typename Iterator, typename Container>
class normal_iterator {
 protected:
    Iterator memory_current;
 public:
    typedef typename ft::iterator_traits<Iterator>::iterator_category    iterator_category;
    typedef typename ft::iterator_traits<Iterator>::value_type           value_type;
    typedef typename ft::iterator_traits<Iterator>::difference_type      difference_type;
    typedef typename ft::iterator_traits<Iterator>::reference            reference;
    typedef typename ft::iterator_traits<Iterator>::pointer              pointer;

    normal_iterator(void);
    explicit normal_iterator(const Iterator& i);

    reference operator*(void) const;
    pointer operator->(void) const;
    normal_iterator& operator++(void);
    normal_iterator operator++(int);
    normal_iterator& operator--(void);
    normal_iterator operator--(int);
    reference operator[](const difference_type& n) const;
    normal_iterator& operator+=(const difference_type& n);
    normal_iterator& operator-=(const difference_type& n);
    normal_iterator operator+(const difference_type& n) const;
    normal_iterator operator-(const difference_type& n) const;

    const Iterator& base(void) const;
};

template<typename IteratorL, typename IteratorR, typename Container>
bool operator==(const normal_iterator<IteratorL, Container>& lhs,
                const normal_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator==(const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator!=(const normal_iterator<IteratorL, Container>& lhs,
                const normal_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator!=(const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<(const normal_iterator<IteratorL, Container>& lhs,
                const normal_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator<(const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>(const normal_iterator<IteratorL, Container>& lhs,
                const normal_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator>(const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<=(const normal_iterator<IteratorL, Container>& lhs,
                const normal_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator<=(const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>=(const normal_iterator<IteratorL, Container>& lhs,
                const normal_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator>=(const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::normal_iterator<IteratorL, Container>::difference_type operator-(
    const ft::normal_iterator<IteratorL, Container>& lhs,
    const ft::normal_iterator<IteratorR, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::normal_iterator<IteratorL, Container>::difference_type operator+(
    typename ft::normal_iterator<IteratorL, Container>::difference_type n,
    const ft::normal_iterator<IteratorR, Container>& i);

}  // namespace ft

#include "./normal_iterator.tpp"

#endif  // CPP_CONTAINERS_HEADERS_NORMAL_ITERATOR_HPP_
