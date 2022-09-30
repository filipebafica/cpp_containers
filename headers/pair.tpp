// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./pair.hpp"

template<typename T1, typename T2>
ft::pair<T1, T2>::pair(void) : first(), second() {}

template<typename T1, typename T2>
ft::pair<T1, T2>::pair(const T1& a, const T2& b) : first(a), second(b) {}

template<typename T1, typename T2>
template<typename U1, typename U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

template<typename T1, typename T2>
ft::pair<T1, T2>& ft::pair<T1, T2>::operator=(const pair& rhs) {
    this->first = rhs.first;
    this->second = rhs.second;
    return (*this);
}

template<typename T1, typename T2>
ft::pair<T1, T2>::~pair(void) {}

template<typename T1, typename T2>
ft::pair<T1, T2> ft::make_pair(T1 a, T2 b) {
    return (ft::pair<T1, T2>(a, b));
}

template<typename T1, typename T2>
bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template<typename T1, typename T2>
bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
    return (!(lhs == rhs));
}

template<typename T1, typename T2>
bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
    return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template<typename T1, typename T2>
bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1, T2>& rhs) {
    return (!(rhs < lhs));
}

template<typename T1, typename T2>
bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
    return (rhs < lhs);
}

template<typename T1, typename T2>
bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
    return (!(lhs < rhs));
}
