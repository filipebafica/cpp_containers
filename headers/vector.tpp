// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <iostream>
#include "./vector.hpp"

/************************************* CONSTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : vector_base<T, Alloc>(alloc) {
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) : vector_base<T, Alloc>(n, alloc) {
    this->unitialized_fill_n_a(this->memory_impl.memory_start, n, value);
    this->memory_impl.memory_finish = this->memory_impl.memory_start + n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc) : vector_base<T, Alloc>(std::distance(first, last), alloc) {
    typedef typename ft::iterator_traits<iterator>::iterator_category iterator_category;
    this->memory_range_initialize(first, last, iterator_category());
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc>& src) : vector_base<T, Alloc>(src.size(), src.get_allocator()) {
    this->unitialized_copy_a(src.begin(), src.end(), this->memory_impl.memory_start);
    this->memory_impl.memory_finish = this->memory_impl.memory_start + std::distance(src.begin(), src.end());
}

template<class T, class Alloc>
ft::vector<T, Alloc>& ft::vector<T, Alloc>::operator=(const vector& rhs) {
    if (&rhs == this)
        return (*this);
    // if rhs length is greater than 
    // lhs hold capacity in currently allocated storage
    const size_type rhs_len = rhs.size();
    if (rhs_len > this->capacity()) {
        pointer tmp = this->memory_allocate_and_copy(rhs_len, rhs.begin(), rhs.end());
        this->destroy(this->memory_impl.memory_start, this->memory_impl.memory_finish);
        this->memory_deallocate(this->memory_impl.memory_start, this->memory_impl.memory_end_of_storage - this->memory_impl.memory_start);
        this->memory_impl.memory_start = tmp;
        this->memory_impl.memory_end_of_storage = this->memory_impl.memory_start + rhs_len;
    }
    // if lhs number of elements is greater or equal than 
    // rhs hold capacity in currently allocated storage
    else if (this->size() >= rhs_len) {
        // iterator i(std::copy(rhs.begin(), rhs.end(), this->begin()));
        // std::_Destroy(i, this->end(), this->get_allocator());
        std::copy(rhs.begin(), rhs.end(), this->begin());
        this->destroy(this->memory_impl.memory_start + rhs_len, this->memory_impl.memory_finish);
    } 
    // if rhs length is less than 
    // lhs hold capacity in currently allocated storage
    else {
        // will copy from rhs the lhs number of elements into lhs
        std::copy(rhs.begin(), rhs.begin() + this->size(), this->memory_impl.memory_start);
        // will construct the remaining elements from rhs into lhs
        this->unitialized_copy_a(rhs.begin() + this->size(), rhs.end(), this->memory_impl.memory_finish);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + rhs_len;
    return (*this);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::allocator_type ft::vector<T, Alloc>::get_allocator(void) const {
    return (this->memory_impl);
}

/************************************* DESTRUCTORS *************************************/
template<class T, class Alloc>
ft::vector<T, Alloc>::~vector(void) {
    this->destroy(this->memory_impl.memory_start, this->memory_impl.memory_finish);
}

/************************************* MEMBER FUNCTIONS *************************************/
// element access
template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::at(size_type n) {
    if (n > this->size())
        throw std::out_of_range("vector::range_check");
    return ((*this)[n]);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(size_type n) const {
    if (n > this->size())
        throw std::out_of_range("vector::range_check");
    return ((*this)[n]);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front(void) {
    return (*this->begin());
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front(void) const {
    return (*this->begin());
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back(void) {
    return (*(this->end() - 1));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back(void) const {
    return (*(this->end() -1));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data(void) {
    return (&*this->begin());
}

template<class T, class Alloc>
const typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data(void) const {
    return (&*this->begin());
}

// iterators
template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin(void) {
    return (iterator(this->memory_impl.memory_start));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin(void) const {
    return (const_iterator(this->memory_impl.memory_start));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end(void) {
    return (iterator(this->memory_impl.memory_finish));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end(void) const {
    return (const_iterator(this->memory_impl.memory_finish));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin(void) {
    return (reverse_iterator(this->end()));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin(void) const {
    return (const_reverse_iterator(this->end()));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend(void) {
    return (reverse_iterator(this->begin()));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend(void) const {
    return (const_reverse_iterator(this->begin()));
}

// capacity
template<class T, class Alloc>
bool ft::vector<T, Alloc>::empty(void) const {
    return (this->begin() == this->end());
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size(void) const {
    return (typename ft::vector<T, Alloc>::size_type(this->end() - this->begin()));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size(void) const {
    // ptrdiff_t (ptrdiff_t) is a type able to represent
    // the result of any valid pointer subtraction operation
    // then, we can't store more than ptrdiff_t::max /sizeof(value_type)
    return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::reserve(size_type n) {
    if (n > this->max_size()) {
        throw std::length_error("vector::reserve");
    }
    if (this->capacity() < n) {
        const size_type old_size = this->size();
        pointer tmp = this->memory_allocate_and_copy(n,
                                                     iterator(this->memory_impl.memory_start),
                                                     iterator(this->memory_impl.memory_finish));
        this->destroy(this->memory_impl.memory_start, this->memory_impl.memory_finish);
        this->memory_deallocate(this->memory_impl.memory_start, this->memory_impl.memory_end_of_storage
                                                                - this->memory_impl.memory_start);
        this->memory_impl.memory_start = tmp;
        this->memory_impl.memory_finish = tmp + old_size;
        this->memory_impl.memory_end_of_storage = this->memory_impl.memory_start + n;
    }
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity(void) const {
    return (
        size_type(const_iterator(this->memory_impl.memory_end_of_storage) - this->begin())
    );
}

// modifiers
template<class T, class Alloc>
void ft::vector<T, Alloc>::assign(size_type n, const value_type& value) {
    this->memory_fill_assign(n, value);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::assign(iterator first, iterator last) {
    typedef typename ft::is_integral<iterator>::type integral;
    if (integral() == true_type())
        return ;
    typedef typename ft::iterator_traits<iterator>::iterator_category iter_category;
    this->memory_assign_aux(first, last, iter_category());
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::clear(void) {
    this->erase(this->begin(), this->end());
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(iterator position, const value_type& value) {
    const size_type n = position - this->begin();

    // check if there is space and the postion to insert is at the end
    // if so an insertion will take place
    if (this->memory_impl.memory_finish != this->memory_impl.memory_end_of_storage
        && position == this->end()) {
            this->memory_impl.construct(this->memory_impl.memory_finish, value);
            ++this->memory_impl.memory_finish;
        }
        else {
            this->memory_insert_aux(position, value);
        }
        return (this->begin() + n);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type& value) {
    return this->memory_fill_insert(position, n, value);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::insert(iterator position, iterator first, iterator last) {
    typedef typename ft::is_integral<iterator>::type integral;
    if (integral() == true_type())
        return ;
    typedef typename ft::iterator_traits<iterator>::iterator_category iter_category;
    this->memory_range_insert(position, first, last, iter_category());
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator position) {
    if (position + 1 != this->end()) {
        // copy position + 1 into postion this makes what position held to be erased
        std::copy(position + 1, this->end(), position);
    }
    // since thre is one less element, the memory finish must be decreased one position
    --this->memory_impl.memory_finish;
    // destroy remaining element
    this->memory_impl.destroy(this->memory_impl.memory_finish);
    return (position);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator first, iterator last) {
    // initialize an iterator copying FROM the last parameter to this container's end INTO 
    // the area pointed to by first parameter
    iterator i(std::copy(last, this->end(), first));
    // 'i' will return an iterator pointing to the end
    // of the copied area
    // erase will delete from that pointer to the end of container
    this->destroy(i, this->end());
    // the finish will be moved back the length erased (last - first)
    this->memory_impl.memory_finish = this->memory_impl.memory_finish - (last - first);
    return (first);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::push_back(const value_type& value) {
    if (this->memory_impl.memory_finish != this->memory_impl.memory_end_of_storage) {
        this->memory_impl.construct(this->memory_impl.memory_finish, value);
        ++this->memory_impl.memory_finish;
    }
    else {
        this->memory_insert_aux(this->end(), value);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::pop_back(void) {
    --this->memory_impl.memory_finish;
    this->memory_impl.destroy(this->memory_impl.memory_finish);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::resize(size_type n, value_type value) {
    if (n < this->size()) {
        this->erase(this->begin() + n, this->end());
    }
    else {
        this->insert(this->end(), n - this->size(), value);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::swap(vector& x) {
    std::swap(this->memory_impl.memory_start, x.memory_impl.memory_start);
    std::swap(this->memory_impl.memory_finish, x.memory_impl.memory_finish);
    std::swap(this->memory_impl.memory_end_of_storage, x.memory_impl.memory_end_of_storage);
}

/************************************* PRIVATE MEMBER FUCNTIONS *************************************/
template<class T, class Alloc>
void ft::vector<T, Alloc>::unitialized_fill_n_a(pointer memory_start, size_type n, const value_type& value) {
    for (; n > 0; n--, memory_start++) {
        this->get_allocator().construct(memory_start, value);
    }
};

template<class T, class Alloc>
void ft::vector<T, Alloc>::unitialized_copy_a(iterator first, iterator last, pointer memory_start) {
    // construct from first to last into memory_start
    for (; first != last; memory_start++, first++) {
        this->get_allocator().construct(memory_start, *first);
    }
};

template<class T, class Alloc>
void ft::vector<T, Alloc>::unitialized_copy_a(const_iterator first, const_iterator last, pointer memory_start) {
    // construct from first to last into memory_start
    for (; first != last; memory_start++, first++) {
        this->get_allocator().construct(memory_start, *first);
    }
};

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::unitialized_copy_a(iterator first, iterator last, iterator result) {
    // construct from first to last into result
    iterator curr = result;
    for (; first != last; curr++, first++) {
        this->get_allocator().construct(&*curr, *first);
    }
    return (curr);
};

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_initialize(iterator first, iterator last, std::input_iterator_tag) {
    for (; first != last; ++first) {
        this->push_back(*first);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_initialize(iterator first, iterator last, std::forward_iterator_tag) {
    const size_type n = std::distance(first, last);
    pointer curr = this->memory_impl.memory_start;
    for (int i = n; i > 0; i--, curr++, first++) {
        this->get_allocator().construct(curr, *first);
    }
    this->memory_impl.memory_finish = this->memory_impl.memory_start + n;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_range_insert(iterator position, iterator first, iterator last,
                                                std::input_iterator_tag) {
    for (; first != last; ++first) {
        position = insert(position, *first);
        ++position;
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::destroy(value_type* p) {
    p->~T();
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::destroy(pointer memory_start, pointer memory_finish) {
    for (; memory_start != memory_finish; memory_start++) {
        this->get_allocator().destroy(memory_start);
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::destroy(iterator first, iterator last) {
    for (; first != last; first++) {
        this->destroy(&*first.base());
    }
}

/************************************* PROTECTED MEMBER FUCNTIONS *************************************/
template<class T, class Alloc>
typename ft::vector<T, Alloc>::pointer ft::vector<T, Alloc>::memory_allocate_and_copy(size_type n,
    iterator first, iterator last) {
        pointer result = this->memory_allocate(n);
        this->unitialized_copy_a(first, last, result);
        return (result);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::pointer ft::vector<T, Alloc>::memory_allocate_and_copy(size_type n,
    const_iterator first, const_iterator last) {
        pointer result = this->memory_allocate(n);
        this->unitialized_copy_a(first, last, result);
        return (result);
}

template<class T, class Alloc>
void  ft::vector<T, Alloc>::memory_fill_assign(size_type n, const value_type& value) {
    // if the number of elements to fill (n) is greater than the current allocation capacity
    // if yes, creates a new vector (tmp) with the intended capacity and swap pointers
    if (n > this->capacity()) {
        vector tmp(n, value);
        tmp.swap(*this);
    }
    // n is less or equal thand capacity but greater than current number os elements
    else if (n > size()) {
        std::fill(this->begin(), this->end(), value);
        this->unitialized_fill_n_a(this->memory_impl.memory_finish, n - this->size(), value);
        this->memory_impl.memory_finish += n - size();
    }
    else {
        // fill the range 'n' with 'value'
        std::fill_n(this->begin(), n, value);
        //erase from the end of range 'n' untill the end of this vector
        this->erase(this->begin() + n, this->end());
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_assign_aux(iterator first, iterator last, std::input_iterator_tag) {
    // will replace this vector with the content from first to last params
    iterator curr(this->begin());
    for (; first != last && curr != this->end(); ++curr, ++first) {
        *curr = *first;
    }
    // if the assign was completed from first to last params
    // the rest of this vector will be erased
    // if not, an insertion will be made from this vector's end
    if (first == last)
        this->erase(curr, this->end());
    else
        this->insert(this->end(), first, last);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_fill_insert(iterator position, size_type n, const value_type& value) {
    if (n != 0) {
        //if the unused space allocated is greater than the insertion attempt size
        if (size_type(this->memory_impl.memory_end_of_storage - this->memory_impl.memory_finish) >= n) {
            value_type value_copy = value;
            const size_type elements_after_position = this->end() - position;
            iterator old_finish(this->memory_impl.memory_finish);
            if (elements_after_position > n) {
                this->unitialized_copy_a(iterator(this->memory_impl.memory_finish - n),
                                            iterator(this->memory_impl.memory_finish),
                                            this->memory_impl.memory_finish);
                this->memory_impl.memory_finish += n;
                std::copy_backward(position, old_finish - n, old_finish);
                std::fill(position, position + n, value_copy);
            }
            else {
                this->unitialized_fill_n_a(this->memory_impl.memory_finish,
                                            n - elements_after_position,
                                            value_copy);
                this->memory_impl.memory_finish += n - elements_after_position;
                this->unitialized_copy_a(position, old_finish,
                                            this->memory_impl.memory_finish);
                this->memory_impl.memory_finish += elements_after_position;
                std::fill(position, old_finish, value_copy);
            }
        }
        // unused space allocated is not greater than the insertion attempt size
        else {
            const size_type old_size = this->size();
            // check if there is enough space availabe
            if (this->max_size() - old_size < n)
                throw std::length_error("vector::memory_fill_insert");

            // extra allocation size is defined here
            size_type len = old_size + std::max(old_size, n);
            // this can true only if old_size is 0,then len wil be 1
            if (len < old_size)
                len = this->max_size();

            iterator new_start(this->memory_allocate(len));
            iterator new_finish(new_start);
            try {
                // copy from this vector begin to position parameter into new_start
                new_finish = this->unitialized_copy_a(
                    this->begin(),
                    position,
                    iterator(new_start)
                );
                this->unitialized_fill_n_a(
                    &*new_finish,
                    n,
                    value
                );
                new_finish += n;
                new_finish = this->unitialized_copy_a(
                    position,
                    this->end(),
                    new_finish
                );
            }
            catch(...) {
                this->destroy(new_start, new_finish);
                this->memory_deallocate(&*new_start.base(), len);
                throw;
            }
            // destroy current memory and set it to the new allocation
            this->destroy(this->begin(), this->end());
            this->memory_deallocate(this->memory_impl.memory_start,
                                    this->memory_impl.memory_end_of_storage - 
                                    this->memory_impl.memory_start);
            this->memory_impl.memory_start = &*new_start.base();
            this->memory_impl.memory_finish = &*new_finish.base();
            this->memory_impl.memory_end_of_storage = &*new_start.base() + len;
        }
    }
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::memory_insert_aux(iterator position, const value_type& value) {
    // check if there is sapce, the last element will be copied to finish + 1
    // then, elements will be copied  from finish -1 to position + 1
    // finally, the insertion value will be placed at the postion param
    // thils is equivalent to 'move foward' all elments one postion
    if (this->memory_impl.memory_finish != this->memory_impl.memory_end_of_storage) {
        this->memory_impl.construct(this->memory_impl.memory_finish, *(this->memory_impl.memory_finish - 1));
        ++this->memory_impl.memory_finish;
        value_type tmp = value;
        std::copy_backward(position,
            iterator(this->memory_impl.memory_finish - 2),
            iterator(this->memory_impl.memory_finish - 1)
        );
        *position = tmp;
    }
    else {
        const size_type old_size = this->size();
        // check if the max size was reached
        if (old_size ==  this->max_size())
            throw std::length_error("vector::_memory_insert_aux");

        // if the previous size is different than 0, len will be doubled
        // if not, len will be 1
        size_type len = old_size != 0 ? 2 * old_size : 1;
        // this can true only if old_size is 0,then len wil be 1
        if (len < old_size)
            len = this->max_size();

        iterator new_start(this->memory_allocate(len));
        iterator new_finish(new_start);
        try {
            // copy from this vector begin to position parameter into new_start
            new_finish = this->unitialized_copy_a(
                this->begin(),
                position,
                new_start
            );
            this->memory_impl.construct(new_finish.base(), value);
            ++new_finish;
            new_finish = this->unitialized_copy_a(position, this->end(), new_finish);
        }
        catch(...) {
            this->destroy(new_start, new_finish);
            this->memory_deallocate(&*new_start.base(), len);
            throw;
        }
        // destroy current memory and set it to the new allocation
        this->destroy(this->begin(), this->end());
        this->memory_deallocate(this->memory_impl.memory_start,
                                this->memory_impl.memory_end_of_storage - 
                                this->memory_impl.memory_start);
        this->memory_impl.memory_start = &*new_start.base();
        this->memory_impl.memory_finish = &*new_finish.base();
        this->memory_impl.memory_end_of_storage = &*new_start.base() + len;
    }
}

/************************************* MEMBER OPERATORS OVERLOAD *************************************/
template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::operator[](size_type n) {
    if (n > this->size())
        throw std::out_of_range("vector::range_check");
    return (*(this->begin() + n));
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::operator[](size_type n) const {
    if (n > this->size())
        throw std::out_of_range("vector::range_check");
    return (*(this->begin() + n));
}

/************************************* NON-MEMBER OPERATORS OVERLOAD *************************************/
template<class T, class Alloc>
bool ft::operator==(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return (
            lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin())
        );
}

template<class T, class Alloc>
bool ft::operator<(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return (std::lexicographical_compare(
            lhs.begin(), lhs.end(), rhs.begin(), rhs.end()
        ));
}

template<class T, class Alloc>
bool ft::operator!=(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return !(lhs == rhs);
}

template<class T, class Alloc>
bool ft::operator>(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return (rhs < lhs);
}

template<class T, class Alloc>
bool ft::operator<=(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return !(rhs < lhs);
}

template<class T, class Alloc>
bool ft::operator>=(
    const ft::vector<T, Alloc>& lhs,
    const ft::vector<T, Alloc>& rhs) {
        return !(lhs < rhs);
}

/************************************* NON-MEMBER FUNCTIONS *************************************/
template<class T, class Alloc>
void ft::swap(
        const ft::vector<T, Alloc>& x,
        const ft::vector<T, Alloc>& y) {
            x.swap(y);
}
