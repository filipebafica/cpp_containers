// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_RB_ITERATOR_HPP_
#define CPP_CONTAINERS_HEADERS_RB_ITERATOR_HPP_
#include "./iterator_base_types.hpp"
#include "./red_black_tree.hpp"

namespace ft {

template<typename Key_type, typename Value_type, typename Key_compare, typename Alloc>
class red_black_tree;

template<typename Iterator, typename Container>
class rb_iterator {
 protected:
    Iterator memory_current;

 public:
    typedef typename Container::value_type          value_type;
    typedef typename Container::value_type&         reference;
    typedef typename Container::value_type*         pointer;
    typedef std::bidirectional_iterator_tag         iterator_category;
    typedef ptrdiff_t                               difference_type;


    rb_iterator(void);
    explicit rb_iterator(const Iterator& i);
    rb_iterator(const rb_iterator& src);

    rb_iterator& operator=(const rb_iterator& src);
    reference operator*(void) const;
    pointer operator->(void) const;
    rb_iterator& operator++(void);
    rb_iterator operator++(int);
    rb_iterator& operator--(void);
    rb_iterator operator--(int);
    const Iterator& base(void) const;
};

template<typename IteratorL, typename IteratorR, typename Container>
bool operator==(const rb_iterator<IteratorL, Container>& lhs,
                const rb_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator==(const rb_iterator<Iterator, Container>& lhs,
                const rb_iterator<Iterator, Container>& rhs);

template<typename IteratorL, typename IteratorR, typename Container>
bool operator!=(const rb_iterator<IteratorL, Container>& lhs,
                const rb_iterator<IteratorR, Container>& rhs);

template<typename Iterator, typename Container>
bool operator!=(const rb_iterator<Iterator, Container>& lhs,
                const rb_iterator<Iterator, Container>& rhs);

}  // namespace ft

#include "./rb_iterator.tpp"

#endif  // CPP_CONTAINERS_HEADERS_RB_ITERATOR_HPP_
