// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_RB_REVERSE_ITERATOR_HPP_
#define CPP_CONTAINERS_HEADERS_RB_REVERSE_ITERATOR_HPP_
#include "./iterator_base_types.hpp"
#include "./red_black_tree.hpp"

namespace ft {

template<typename Key_type, typename Value_type, typename Key_compare, typename Alloc>
class red_black_tree;

template<typename Iterator, typename Container>
class rb_reverse_iterator
: public iterator<typename iterator_traits<Iterator>::iterator_category,
                  typename iterator_traits<Iterator>::value_type,
                  typename iterator_traits<Iterator>::difference_type,
                  typename iterator_traits<Iterator>::pointer,
                  typename iterator_traits<Iterator>::reference> {
 protected:
    Iterator memory_current;

 public:
    typedef Iterator                                                     iterator_type;
    typedef typename ft::iterator_traits<Iterator>::difference_type      difference_type;
    typedef typename ft::iterator_traits<Iterator>::reference            reference;
    typedef typename ft::iterator_traits<Iterator>::pointer              pointer;


    rb_reverse_iterator(void);
    explicit rb_reverse_iterator(const Iterator& i);
    rb_reverse_iterator(const rb_reverse_iterator& src);

    rb_reverse_iterator& operator=(const rb_reverse_iterator& src);
    reference operator*(void) const;
    pointer operator->(void) const;
    rb_reverse_iterator& operator++(void);
    rb_reverse_iterator operator++(int);
    rb_reverse_iterator& operator--(void);
    rb_reverse_iterator operator--(int);
    reference operator[](const difference_type& n) const;
    rb_reverse_iterator& operator+=(const difference_type& n);
    rb_reverse_iterator& operator-=(const difference_type& n);
    rb_reverse_iterator operator+(const difference_type& n) const;
    rb_reverse_iterator operator-(const difference_type& n) const;

    const Iterator& base(void) const;
};

}  // namespace ft

#include "./rb_reverse_iterator.tpp"

#endif  // CPP_CONTAINERS_HEADERS_RB_REVERSE_ITERATOR_HPP_
