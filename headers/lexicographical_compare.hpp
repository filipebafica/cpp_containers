// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.
#ifndef CPP_CONTAINERS_HEADERS_LEXICOGRAPHICAL_COMPARE_HPP_
#define CPP_CONTAINERS_HEADERS_LEXICOGRAPHICAL_COMPARE_HPP_

namespace ft {
// Checks if the first range [first1, last1) is lexicographically
// less than the second range [first2, last2)

// The first mismatching element defines which range is
// lexicographically less or greater than the other
template <class Iteratorr1, class Iteratorr2>
bool lexicographical_compare(Iteratorr1 first1, Iteratorr2 last1,
                             Iteratorr1 first2, Iteratorr2 last2) {
    while (first1 != last1) {
        if (first2 == last2 || *first2 < *first1) {
            return (false);
        } else if (*first1 < *first2) {
            return (true);
        }
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template <class Iteratorr1, class Iteratorr2, class Compare>
bool lexicographical_compare(Iteratorr1 first1, Iteratorr2 last1,
                             Iteratorr1 first2, Iteratorr2 last2,
                             Compare compare) {
    while (first1 != last1) {
        if (compare(*first2, *first1)) {
            return (false);
        } else if (compare(*first1, *first2)) {
            return (true);
        }
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}
}  // namespace ft

#endif  // CPP_CONTAINERS_HEADERS_LEXICOGRAPHICAL_COMPARE_HPP_
