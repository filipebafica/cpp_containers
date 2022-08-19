// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_ITERATOR_TAGS_HPP_
#define CPP_CONTAINERS_HEADERS_ITERATOR_TAGS_HPP_

namespace ft {
struct input_iterator_tag {};
struct output_iterator_tag {};
struct foward_iterator_tag : public input_iterator_tag {};
struct biderectinal_iterator_tag : public foward_iterator_tag {};
struct random_access_iterator_tag : public biderectinal_iterator_tag {};
}  // namespace ft

#endif  // CPP_CONTAINERS_HEADERS_ITERATOR_TAGS_HPP_
