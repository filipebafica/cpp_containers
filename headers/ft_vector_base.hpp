// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_
#define CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_

#include <memory>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
struct VectorBase {
    struct VectorImpl : public Alloc {
        T* memoryStart;
        T* memoryFinish;
        T* memoryEndOfStorage;
        explicit VectorImpl(Alloc const& alloc) :
        Alloc(alloc), memoryStart(0), memoryFinish(0), memoryEndOfStorage(0)
        {}
    };

    /******************** MEMBER TYPES ********************/
    VectorImpl memoryImpl;
    typedef Alloc allocator_type;


    /******************** CONSTRUCTORS ********************/
    explicit VectorBase(const allocator_type& alloc);
};
}  // namespace ft

#include "./ft_vector_base.tpp"

#endif  // CPP_CONTAINERS_HEADERS_VECTOR_BASE_HPP_
