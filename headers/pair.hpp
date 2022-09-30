#ifndef CPP_CONTAINERS_HEADERS_PAIR_HPP_
#define CPP_CONTAINERS_HEADERS_PAIR_HPP_

namespace ft {
template<typename T1, typename T2>
class pair {
 public:
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair(void);
    pair(const T1& a, const T2& b);
    template<typename U1, typename U2>
    explicit pair(const pair<U1, U2>& p);
    pair& operator=(const pair& rhs);
    ~pair(void);
};

template<typename T1, typename T2>
ft::pair<T1, T2> make_pair(T1 a, T2 b);

template<typename T1, typename T2>
bool operator==(const ft::pair<T1, T2>& lhs,
                const ft::pair<T1, T2>& rhs);

template<typename T1, typename T2>
bool operator!=(const ft::pair<T1, T2>& lhs,
                const ft::pair<T1, T2>& rhs);

template<typename T1, typename T2>
bool operator<(const ft::pair<T1, T2>& lhs,
                const ft::pair<T1, T2>& rhs);

template<typename T1, typename T2>
bool operator<=(const ft::pair<T1, T2>& lhs,
                const ft::pair<T1, T2>& rhs);

template<typename T1, typename T2>
bool operator>(const ft::pair<T1, T2>& lhs,
                const ft::pair<T1, T2>& rhs);

template<typename T1, typename T2>
bool operator>=(const ft::pair<T1, T2>& lhs,
                const ft::pair<T1, T2>& rhs);
}  // namespace ft

#include "./pair.tpp"

#endif  // CPP_CONTAINERS_HEADERS_PAIR_HPP_
