// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_
#define CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_

#include <memory>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
struct VectorBase {
    struct MemoryImpl : public Alloc {
        T* memoryStart;
        T* memoryFinish;
        T* memoryEndOfStorage;
        explicit MemoryImpl(Alloc const& alloc) :
        Alloc(alloc), memoryStart(0), memoryFinish(0), memoryEndOfStorage(0) {}
    };

    /******************** MEMBER TYPES ********************/
    MemoryImpl memoryImpl;
    typedef Alloc allocator_type;

    /******************** CONSTRUCTORS ********************/
    explicit VectorBase(const allocator_type& alloc);
    VectorBase(size_t n, const allocator_type& alloc);

    /******************** MEMBER FUNCTIONS ********************/
    T* memoryAllocate(size_t n);
};
}  // namespace ft

#include "./vector_base.tpp"

#endif  // CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_
