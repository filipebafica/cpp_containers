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
    ft::node<T> *z = new ft::node<T>;
    z->color = 'B';
    z->key = key;
    z->parent = NULL;
    z->left = NULL;
    z->right = NULL;
    return (z);
}

template<typename T>
void ft::red_black_tree<T>::insert_node(T key) {
    ft::node<T> *z = this->create_node(key);
    ft::node<T> *x = this->root;
    ft::node<T> *y = NULL;

    // descend until reaching a leaf
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // attatch the z to the leaf found
    z->parent = y;

    // if y is NULL, the tree is empty (loop above won't start) 
    // z bocomes the root
    if (y == NULL) {
        this->root = z;
    } 
    // if z->key is less than y->key (y is z's parent), 
    // then z will go the left leaf
    else if (z->key < y->key) {
         y->left = z;
    }
    // if z->key is not less than y->key (y is z's parent), 
    // then z will go the right leaf
    else {
        y->right = z;
    }
    z->left = NULL;
    z->right = NULL;
    z->color = 'R';
    this->insert_node_fixup(z);
}

template<typename T>
void ft::red_black_tree<T>::delete_node(T key) {
    ft::node<T> *z = this->search_node(key);
    if (z == NULL)
        return;

    ft::node<T> *y = z;
    ft::node<T> *x = NULL;
    char y_original_color = y->color;

    // if z doesn't have a left child
    // replace z by its right child
    if (z->left == NULL) {
        x = z->right;
        this->transplant_node(z, z->right);
    } 
    // if z doesn't have a right child
    // replace z by its left child
    else if (z->right == NULL) {
        x = z->left;
        this->transplant_node(z, z->left);
    }
    // if z doesn't have any child
    // y is z's successor
    // y = minimum starting form z->right
    else {
        y = this->minimum_node(z->right);
        y_original_color = y->color;
        x = y->right;
        // if y's father is down the tree
        if (y != z->right) {
            // replace y by its right child
            this->transplant_node(y, y->right);
            // z's right child becomes y's right child
            y->right = z->right;
            y->right->parent = y;
        } 
        else if (x) {
            x->parent = y;
            //replace z by its successor y
            // and gives z's left child to y
            // which had no left child
            this->transplant_node(z, y);
            y->left = z.left;
            y->left->parent = y;
            y->color = z->color;
        }
    }
    if (y_original_color == 'B') {
        this->delete_fixup(x);
    }
}

template<typename T>
ft::node<T> *ft::red_black_tree<T>::search_node(T key) {
    return(search_node_aux(this->root, key));
}

template<typename T>
ft::node<T> *ft::red_black_tree<T>::search_node_aux(ft::node<T> *x, T key) {
    if (x == NULL || key == x->key) {
        return (x);
    } else if (key < x->key) {
        return (this->search_node_aux(x->left, key));
    } else {
        return (this->search_node_aux(x->right, key));
    }
}

template<typename T>
void ft::red_black_tree<T>::insert_node_fixup(ft::node<T> *z) {
    ft::node<T> *y;
    while (z->parent && z->parent->color == 'R') {
        // if z's parent is a left child
        // y becomes z's uncle
        if (z->parent->parent && z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            // if z's parent && uncle are red
            // case 1
            if (y && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            // z's parent && uncle are not red
            else {
                //case 2
                if (z == z->parent->right) {
                    z = z->parent;
                    this->left_rotate(z);
                }
                // case 3
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                this->right_rotate(z->parent->parent);
            }
        }
        // z's parent is a right child
        else if (z->parent->parent && z->parent == z->parent->parent->right) {
            y = z->parent->parent->left;
            // if z's parent && uncle are red
            // case 1
            if (y && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } 
            // z's parent && uncle are not red
            else {
                // case 2
                if (z == z->parent->left) {
                    z = z->parent;
                    this->right_rotate(z);
                }
                // case 3
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                this->left_rotate(z->parent->parent);
            }
        }
    }
    this->root->color = 'B';
}

template<typename T>
void ft::red_black_tree<T>::left_rotate(ft::node<T> *x) {
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
void ft::red_black_tree<T>::right_rotate(ft::node<T> *x) {
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
void ft::red_black_tree<T>::transplant_node(ft::node<T> *u, ft::node<T> *v) {
    if (u->parent == NULL) {
        this->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template<typename T>
void ft::red_black_tree<T>::print_tree_debug(void) {
    print_tree_debug_aux(this->root);
}

template<typename T>
void ft::red_black_tree<T>::print_tree_debug_aux(ft::node<T> *node) {
    if (node != NULL) {
        print_tree_debug_aux(node->left);
        std::cout << "k: " << (node ? node->key : 0)
                  << " | p: " << (node->parent ? node->parent->key : 0)
                  << " | l: " << (node->left ? node->left->key : 0)
                  << " | r: " << (node->right ? node->right->key : 0)
                  << " | c: " << (node->color ? node->color : ' ')
                  << std::endl;
        print_tree_debug_aux(node->right);
    }
}
