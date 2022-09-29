#ifndef CPP_CONTAINERS_HEADERS_PAIR_HPP_
#define CPP_CONTAINERS_HEADERS_PAIR_HPP_


namespace ft {
template<typename T1, typename T2>
class pair {
 public:
    T1 first;
    T2 second;

    pair(void);
    pair(const first_type& first, const second_type& second);
    template<typename U1, typename U2>
    explicit pair(const ft::pair<U1, U2>& p);
    ft::pair& operator=(const ft::pair& rhs);
    ~pair(void);
};

template<typename T1, typename T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u);

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

#endif  // CPP_CONTAINERS_HEADERS_PAIR_HPP_
