// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_
#define CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_

#include <memory>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
struct vector_base {
    struct memory_impl : public Alloc {
        T* memory_start;
        T* memory_finish;
        T* memory_end_of_storage;
        explicit memory_impl(Alloc const& alloc) :
        Alloc(alloc), memory_start(0), memory_finish(0), memory_end_of_storage(0) {}
    };

    /******************** MEMBER TYPES ********************/
    memory_impl memory_impl;
    typedef Alloc allocator_type;

    /******************** CONSTRUCTORS ********************/
    explicit vector_base(const allocator_type& alloc);
    vector_base(size_t n, const allocator_type& alloc);

    /******************** DESTRUCTORS ********************/
    ~vector_base(void);

    /******************** MEMBER FUNCTIONS ********************/
    Alloc get_allocator(void) const;
    T* memory_allocate(size_t n);
    void memory_deallocate(T* memory_start, size_t n);
};
}  // namespace ft

#include "./vector_base.tpp"

#endif  // CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_
