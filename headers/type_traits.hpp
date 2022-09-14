// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_UTILS_HPP_
#define CPP_CONTAINERS_HEADERS_UTILS_HPP_

// #include <type_traits>

namespace ft {

template<class T, T v>
struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
    operator value_type() const { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template<typename T> struct is_integral_base : public false_type {};
template<> struct is_integral_base<bool> : public true_type {};
template<> struct is_integral_base<char> : public true_type {};
template<> struct is_integral_base<wchar_t> : public true_type {};
template<> struct is_integral_base<signed char> : public true_type {};
template<> struct is_integral_base<short int> : public true_type {};
template<> struct is_integral_base<int> : public true_type {};
template<> struct is_integral_base<long int> : public true_type {};
template<> struct is_integral_base<long long int> : public true_type {};
template<> struct is_integral_base<unsigned char> : public true_type {};
template<> struct is_integral_base<unsigned short int> : public true_type {};
template<> struct is_integral_base<unsigned int> : public true_type {};
template<> struct is_integral_base<unsigned long int> : public true_type {};
template<> struct is_integral_base<unsigned long long int> : public true_type {};

template<typename T> struct is_integral : is_integral_base<T> {};
}  // namespace ft

#endif  // CPP_CONTAINERS_HEADERS_UTILS_HPP_
