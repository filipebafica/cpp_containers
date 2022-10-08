// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "./red_black_tree.hpp"

template<typename T>
ft::red_black_tree<T>::red_black_tree(void) {
    this->root = NULL;
}

template<typename T>
ft::red_black_tree<T>::~red_black_tree(void) {
    if (this->root)
        delete this->root;
}

template<typename T>
ft::node<T> *ft::red_black_tree<T>::create_node(T key) {
    ft::node<T> *new_node = new ft::node<T>;
    new_node->color = 'B';
    new_node->key = key;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

template<typename T>
void ft::red_black_tree<T>::insert(T key) {
    ft::node<T> *new_node = this->create_node(key);
    ft::node<T> *x = this->root;
    ft::node<T> *y = NULL;

    // descend until reaching a leaf
    while (x != NULL) {
        y = x;
        if (new_node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // attatch the new_node to the leaf found
    new_node->parent = y;

    // if y is NULL, the tree is empty (loop above won't start) 
    // new_node bocomes the root
    if (y == NULL) {
        this->root = new_node;
    } 
    // if new_node->key is less than y->key (y is new_node's parent), 
    // then new_node will go the left leaf
    else if (new_node->key < y->key) {
         y->left = new_node;
    }
    // if new_node->key is not less than y->key (y is new_node's parent), 
    // then new_node will go the right leaf
    else {
        y->right = new_node;
    }
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->color = 'R';
    this->insert_fixup(new_node);
}

template<typename T>
void ft::red_black_tree<T>::insert_fixup(node<T> *new_node) {
    ft::node<T> *y;
    while (new_node->parent && new_node->parent->color == 'R') {
        // if new_node's parent is a left child
        // y becomes new_node's uncle
        if (new_node->parent->parent && new_node->parent == new_node->parent->parent->left) {
            y = new_node->parent->parent->right;
            // if new_node's parent && uncle are red
            // case 1
            if (y && y->color == 'R') {
                new_node->parent->color = 'B';
                y->color = 'B';
                new_node->parent->parent->color = 'R';
                new_node = new_node->parent->parent;
            }
            // new_node's parent && uncle are not red
            else {
                //case 2
                if (new_node == new_node->parent->right) {
                    new_node = new_node->parent;
                    this->left_rotate(new_node);
                }
                // case 3
                new_node->parent->color = 'B';
                new_node->parent->parent->color = 'R';
                this->right_rotate(new_node->parent->parent);
            }
        }
        // new_node's parent is a right child
        else if (new_node->parent->parent && new_node->parent == new_node->parent->parent->right) {
            y = new_node->parent->parent->left;
            // if new_node's parent && uncle are red
            // case 1
            if (y && y->color == 'R') {
                new_node->parent->color = 'B';
                y->color = 'B';
                new_node->parent->parent->color = 'R';
                new_node = new_node->parent->parent;
            } 
            // new_node's parent && uncle are not red
            else {
                // case 2
                if (new_node == new_node->parent->left) {
                    new_node = new_node->parent;
                    this->right_rotate(new_node);
                }
                // case 3
                new_node->parent->color = 'B';
                new_node->parent->parent->color = 'R';
                this->left_rotate(new_node->parent->parent);
            }
        }
    }
    this->root->color = 'B';
}

template<typename T>
void ft::red_black_tree<T>::left_rotate(node<T> *x) {
    // y becomes the x's right child (since it is a left rotate, right goes up)
    ft::node<T> *y = x->right;
    // turn y's (x->right) left subtree into x's right subtree
    x->right = y->left;
    // x becomes y's left parent
    if (y->left != NULL) {
        y->left->parent = x;
    }

    // x's parent becomes y's parent
    y->parent = x->parent;

    // if x was the root
    // then y becomes the root
    if (x->parent == NULL) {
        this->root = y;
    }
    // otherwise, if x was a left child
    // then y becomes a left child
    else if (x == x->parent->left) {
        x->parent->left = y;
    } 
    // otherwise, x was a right child, and now y is
    else {
        x->parent->right = y;
    }
    // x becomes y's left child
    y->left = x;
    x->parent = y;
}

template<typename T>
void ft::red_black_tree<T>::right_rotate(node<T> *x) {
    // y becomes the x's left child (since it is a right rotate, left goes up)
    ft::node<T> *y = x->left;

    // get the (x's closest less than value) to be at its left
    x->left = y->right;
    // x becomes y's left parent
    if (y->right != NULL) {
        y->right->parent = x;
    }

    // x's parent becomes y's parent
    y->parent = x->parent;

    // if x was the root
    // then y becomes the root
    if (x->parent == NULL) {
        this->root = y;
    }
    // otherwise, if x was a right child
    // then y becomes a right child
    else if (x == x->parent->right) {
        x->parent->right = y;
    } 
    // otherwise, x was a left child, and now y is
    else {
        x->parent->left = y;
    }
    // x becomes y's right child
    y->right = x;
    x->parent = y;
}

template<typename T>
void ft::red_black_tree<T>::print_tree_debug(void) {
    if (this->root != NULL) {
        print_tree_debug(this->root->left);
        std::cout << "k: " << (this->root ? this->root->key : 0)
                  << " | p: " << (this->root->parent ? this->root->parent->key : 0)
                  << " | l: " << (this->root->left ? this->root->left->key : 0)
                  << " | r: " << (this->root->right ? this->root->right->key : 0)
                  << " | c: " << (this->root->color ? this->root->color : ' ')
                  << std::endl;
        print_tree_debug(this->root->right);
    }
}

template<typename T>
void ft::red_black_tree<T>::print_tree_debug(node<T> *node) {
    if (node != NULL) {
        print_tree_debug(node->left);
        std::cout << "k: " << (node ? node->key : 0)
                  << " | p: " << (node->parent ? node->parent->key : 0)
                  << " | l: " << (node->left ? node->left->key : 0)
                  << " | r: " << (node->right ? node->right->key : 0)
                  << " | c: " << (node->color ? node->color : ' ')
                  << std::endl;
        print_tree_debug(node->right);
    }
}
