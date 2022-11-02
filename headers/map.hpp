// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_MAP_HPP_
#define CPP_CONTAINERS_HEADERS_MAP_HPP_

#include <functional>
#include <memory>
#include "./pair.hpp"
#include "./red_black_tree.hpp"

#define MAP_TEMPLATE typename Key, \
                     typename T, \
                     typename Compare, \
                     typename Alloc

#define MAP_TYPES   Key, \
                    T, \
                    Compare, \
                    Alloc

namespace ft {
template<typename Key, typename T, typename Compare = std::less<Key>,
         typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
 public:
    /***************************** MEMBER TYPES *****************************/
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

//  private:
 public:
    typedef ft::red_black_tree<key_type, value_type, key_compare, Alloc> RB_type;
    RB_type                                                              memory_tree;

 public:
    typedef typename Alloc::pointer                    pointer;
    typedef typename Alloc::const_pointer              const_pointer;
    typedef typename Alloc::reference                  reference;
    typedef typename Alloc::const_reference            const_reference;
    typedef typename RB_type::allocator_type           allocator_type;
    typedef typename RB_type::iterator                 iterator;
    typedef typename RB_type::const_iterator           const_iterator;
    typedef typename RB_type::reverse_iterator         reverse_iterator;
    typedef typename RB_type::const_reverse_iterator   const_reverse_iterator;
    typedef typename RB_type::size_type                size_type;
    typedef typename RB_type::difference_type          difference_type;

    /***************************** CONSTRUCTORS *****************************/
    map(void);
    map(iterator first, iterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type());
    map(const map& src);
    map& operator=(const map& rhs);

    /***************************** DESTRUCTORS *****************************/
    ~map(void);

    /******************** MEMBER FUNCTIONS ********************/
    // element access
    mapped_type& operator[](const key_type& k);
    mapped_type& at(const key_type& k);
    const mapped_type& at(const key_type& k) const;

    // iterators
    iterator begin(void);
    const_iterator begin(void) const;
    iterator end(void);
    const_iterator end(void) const;
    // reverse_iterator rbegin(void);
    // const_reverse_iterator rbegin(void) const;
    // reverse_iterator rend(void);
    // const_reverse_iterator rend(void) const;

    // capacity
    bool empty(void) const;
    size_type size(void) const;
    size_type max_size(void) const;

    // modifiers
    void clear(void);
    ft::pair<iterator, bool> insert(const value_type& value);
    // iterator insert(iterator position, const value_type& value);
    // void insert(iterator position, iterator first, iterator last);
    void erase(iterator position);
    void erase(iterator first, iterator last);
    size_type erase(const key_type& k);
    // void swap(map& x);

    // // operations
    // iterator find(const key_type& k);
    // const_iterator find(const key_type& k) const;
    // size_type count(const key_type& k) const;
    // ft::pair<iterator, iterator> equal_range(const key_type& k);
    // ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
    // iterator lower_bound(const key_type& k);
    // const_iterator lower_bound(const key_type& k) const;
    // iterator upper_bound(const key_type& k);
    // const_iterator upper_bound(const key_type& k) const;
};
}  // namespace ft

#include "./map.tpp"


#endif  // CPP_CONTAINERS_HEADERS_MAP_HPP_
