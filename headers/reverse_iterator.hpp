// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_REVERSE_ITERATOR_HPP_
#define CPP_CONTAINERS_HEADERS_REVERSE_ITERATOR_HPP_
#include "./iterator_base_types.hpp"

namespace ft {
template<typename Iterator>
class reverse_iterator
: public iterator<typename iterator_traits<Iterator>::iterator_category,
                  typename iterator_traits<Iterator>::value_type,
                  typename iterator_traits<Iterator>::difference_type,
                  typename iterator_traits<Iterator>::pointer,
                  typename iterator_traits<Iterator>::reference> {
 protected:
    Iterator memory_current;
 public:
    typedef typename ft::iterator_traits<Iterator>::iterator_category    iterator_category;
    typedef typename ft::iterator_traits<Iterator>::value_type           value_type;
    typedef typename ft::iterator_traits<Iterator>::difference_type      difference_type;
    typedef typename ft::iterator_traits<Iterator>::reference            reference;
    typedef typename ft::iterator_traits<Iterator>::pointer              pointer;

    reverse_iterator(void);
    explicit reverse_iterator(const Iterator& i);
    reverse_iterator(const reverse_iterator& src);

    reference operator*(void) const;
    pointer operator->(void) const;
    reverse_iterator& operator++(void);
    reverse_iterator operator++(int);
    reverse_iterator& operator--(void);
    reverse_iterator operator--(int);
    reference operator[](const difference_type& n) const;
    reverse_iterator& operator+=(const difference_type& n);
    reverse_iterator& operator-=(const difference_type& n);
    reverse_iterator operator+(const difference_type& n) const;
    reverse_iterator operator-(const difference_type& n) const;

    const Iterator& base(void) const;
};

template<typename IteratorL, typename IteratorR, typename Container>
bool operator==(const reverse_iterator<IteratorL>& lhs,
                const reverse_iterator<IteratorR>& rhs);

template<typename Iterator, typename Container>
bool operator==(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator!=(const reverse_iterator<IteratorL>& lhs,
                const reverse_iterator<IteratorR>& rhs);

template<typename Iterator, typename Container>
bool operator!=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<(const reverse_iterator<IteratorL>& lhs,
                const reverse_iterator<IteratorR>& rhs);

template<typename Iterator, typename Container>
bool operator<(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>(const reverse_iterator<IteratorL>& lhs,
                const reverse_iterator<IteratorR>& rhs);

template<typename Iterator, typename Container>
bool operator>(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator<=(const reverse_iterator<IteratorL>& lhs,
                const reverse_iterator<IteratorR>& rhs);

template<typename Iterator, typename Container>
bool operator<=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator>=(const reverse_iterator<IteratorL>& lhs,
                const reverse_iterator<IteratorR>& rhs);

template<typename Iterator, typename Container>
bool operator>=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::reverse_iterator<IteratorL>::difference_type operator-(
    const ft::reverse_iterator<IteratorL>& lhs,
    const ft::reverse_iterator<IteratorR>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
typename ft::reverse_iterator<IteratorL>::difference_type operator+(
    typename ft::reverse_iterator<IteratorL>::difference_type n,
    const ft::reverse_iterator<IteratorR>& i);

}  // namespace ft

#include "./reverse_iterator.tpp"

#endif  // CPP_CONTAINERS_HEADERS_reverse_iterator_HPP_
