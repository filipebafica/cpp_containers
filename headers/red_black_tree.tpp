// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include "./red_black_tree.hpp"

#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */

template<RB_NODE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES>::rb_node(
                                    const value_type& data,
                                    char color,
                                    rb_node *parent,
                                    rb_node *left,
                                    rb_node *right
                                )
                                :
                                    data(data),
                                    color(color),
                                    parent(parent),
                                    left(left),
                                    right(right) {}

template<RB_TREE_TEMPLATE>
ft::red_black_tree<RB_TREE_TYPES>::red_black_tree(void) {
}

template<RB_TREE_TEMPLATE>
ft::red_black_tree<RB_TREE_TYPES>::red_black_tree(const key_compare& key_comp, const allocator_type& node_alloc) {

    this->key_comp = key_comp;
    this->rb_node_alloc = node_alloc;
    this->root = NULL;
    this->nil = create_rb_node(ft::pair<
                                        typename value_type::first_type,
                                        typename value_type::second_type
                                    >(
                                        typename value_type::first_type(),
                                        typename value_type::second_type())
                                    );
}

template<RB_TREE_TEMPLATE>
ft::red_black_tree<RB_TREE_TYPES>::~red_black_tree(void) {
    if (this->root)
        delete this->root;
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::create_rb_node(const value_type& data) {
   ft::rb_node<RB_NODE_TYPES> *z = this->rb_node_alloc.allocate(1);
   this->rb_node_alloc.construct(z, ft::rb_node<RB_NODE_TYPES>(
                                                                data,
                                                                'B',
                                                                NULL,
                                                                NULL,
                                                                NULL
                                                            ));
    return (z);
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::insert_rb_node(key_type key) {
   ft::rb_node<RB_NODE_TYPES> *z = this->create_rb_node(key);
   ft::rb_node<RB_NODE_TYPES> *x = this->root;
   ft::rb_node<RB_NODE_TYPES> *y = NULL;

    // descend until reaching a leaf
    // if tree is empty (x == NULL) loop won't start
    while (x != NULL && x != this->nil) {
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
    z->left = this->nil;
    z->right = this->nil;
    z->color = 'R';
    this->insert_rb_node_fixup(z);
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::insert_rb_node_fixup(ft::rb_node<RB_NODE_TYPES> *z) {
   ft::rb_node<RB_NODE_TYPES> *y;
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

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::delete_rb_node(key_type key) {
   ft::rb_node<RB_NODE_TYPES> *z = this->search_rb_node(key);
    if (z == NULL) {
        return;
    }

   ft::rb_node<RB_NODE_TYPES> *y = z;
   ft::rb_node<RB_NODE_TYPES> *x = NULL;
    char y_original_color = y->color;

    // if z doesn't have a left child
    // replace z by its right child
    if (z->left == this->nil) {
        x = z->right;
        this->transplant_rb_node(z, z->right);
    }
    // if z doesn't have a right child
    // replace z by its left child
    else if (z->right == this->nil) {
        x = z->left;
        this->transplant_rb_node(z, z->left);
    }
    // if z has two children
    // y is z's successor
    // y = minimum starting from z->right
    // the successor must be >= than z (that's why get from right)
    // and will get a node without a child
    else {
        y = this->minimum_rb_node(z->right);
        y_original_color = y->color;
        // at end x will be at y's original position
        x = y->right;
        // if y is not z's right child
        if (y != z->right) {
            // replace y by its right child
            this->transplant_rb_node(y, y->right);
            // z's right child becomes y's right child
            y->right = z->right;
            y->right->parent = y;
        }
        else {
            x->parent = y;
        }
        //replace z by its successor y
        // and gives z's left child to y
        // which had no left child
        this->transplant_rb_node(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_original_color == 'B') {
        this->delete_rb_node_fixup(x);
    }
    // delete x;
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::delete_rb_node_fixup(ft::rb_node<RB_NODE_TYPES> *x) {
   ft::rb_node<RB_NODE_TYPES> *w;
    while (x != this->root && x->color == 'B') {
        // if x is a left child
        // w is x's right sibling
        if (x == x->parent->left) {
            w = x->parent->right;
            // case 1
            // w (x's sibling) is red
            // ensures that w and its parent will not be red-red
            // sets w to black
            // sets w->parent to red
            if (w->color == 'R') {
                w->color = 'B';
                w->parent->color = 'R';
                this->left_rotate(w->parent);
                w = x->parent->right;
            }
            // case 2
            // both w's children are black
            //sets w to red
            // x's becomes its parent
            if (w->left->color == 'B' && w->right->color == 'B') {
                    w->color = 'R';
                    x = x->parent;
            }
            else {
                // case 3
                // w's right child is black
                //sets w to red
                if (w->right->color == 'B') {
                    w->left->color = 'B';
                    w->color = 'R';
                    this->right_rotate(w);
                    w = x->parent->right;
                }
                // case 4
                // sets w's color to x->parent's color
                // sets x->paret's color to black
                // sets w's right child to black
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B';
                this->left_rotate(x->parent);
                x = this->root;
            }
        }
        else {
            w = x->parent->left;
            // case 1
            // w (x's sibling) is red
            // ensures that w and its parent will not be red-red
            // sets w to black
            // sets w->parent to red
            if (w->color == 'R') {
                w->color = 'B';
                w->parent->color = 'R';
                this->right_rotate(w->parent);
                w = x->parent->left;
            }
            // case 2
            // both w's children are black
            //sets w to red
            // x's becomes its parent
            if (w->right->color == 'B' && w->left->color == 'B') {
                    w->color = 'R';
                    x = x->parent;
            }
            else {
                // case 3
                // w's left child is black
                //sets w to red
                if (w->left->color == 'B') {
                    w->right->color = 'B';
                    w->color = 'R';
                    this->left_rotate(w);
                    w = x->parent->left;
                }
                // case 4
                // sets w's color to x->parent's color
                // sets x->paret's color to black
                // sets w's left child to black
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
                this->right_rotate(x->parent);
                x = this->root;
            }
        }
    }
    x->color = 'B';
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::search_rb_node(key_type key) {
    return(search_rb_node_aux(this->root, key));
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::search_rb_node_aux(ft::rb_node<RB_NODE_TYPES> *x, key_type key) {
    if (x == NULL || key == x->key) {
        return (x);
    } else if (key < x->key) {
        return (this->search_rb_node_aux(x->left, key));
    } else {
        return (this->search_rb_node_aux(x->right, key));
    }
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::minimum_rb_node(ft::rb_node<RB_NODE_TYPES> *x) {
    while (x->left != this->nil)
        x = x->left;
    return (x);
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::maximum_rb_node(ft::rb_node<RB_NODE_TYPES> *x) {
    while (x->right != this->nil)
        x = x->right;
    return (x);
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::successor_rb_node(ft::rb_node<RB_NODE_TYPES> *x) {
    if (x->right != this->nil) {
        // leftmost node in right subtree
        return (this->minimum_rb_node(x->right));
    }
    // find the lowest x's ancestor
    // whose left child is an x's ancestor
   ft::rb_node<RB_NODE_TYPES> *y = x->parent;
    while (y != this->nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return (y);
}

template<RB_TREE_TEMPLATE>
ft::rb_node<RB_NODE_TYPES> *ft::red_black_tree<RB_TREE_TYPES>::predecessor_rb_node(ft::rb_node<RB_NODE_TYPES> *x) {
    if (x->left != this->nil) {
        // rightmost node in left subtree
        return (this->maximum_rb_node(x->left));
    }
    // find the lowest x's ancestor
    // whose left child is an x's ancestor
   ft::rb_node<RB_NODE_TYPES> *y = x->parent;
    while (y != this->nil && x == y->left) {
        x = y;
        y = y->parent;
    }
    return (y);
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::left_rotate(ft::rb_node<RB_NODE_TYPES> *x) {
    // y becomes the x's right child (since it is a left rotate, right goes up)
   ft::rb_node<RB_NODE_TYPES> *y = x->right;

    // checks if y is valid
    if (!y)
        return;

    // turn y's (x->right) left subtree into x's right subtree
    x->right = y->left;
    // x becomes y's left parent
    if (y->left != this->nil) {
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

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::right_rotate(ft::rb_node<RB_NODE_TYPES> *x) {
    // y becomes the x's left child (since it is a right rotate, left goes up)
   ft::rb_node<RB_NODE_TYPES> *y = x->left;

    // checks if y is valid
    if (!y)
        return;

    // get the (x's closest less than value) to be at its left
    x->left = y->right;
    // x becomes y's left parent
    if (y->right != this->nil) {
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

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::transplant_rb_node(ft::rb_node<RB_NODE_TYPES> *u,ft::rb_node<RB_NODE_TYPES> *v) {
    if (u->parent == NULL) {
        this->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v)
        v->parent = u->parent;
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::print_tree_debug(void) {
    if (this->root) {
        print_tree_debug_aux(this->root, "", true);
    }
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::print_tree_debug_aux(ft::rb_node<RB_NODE_TYPES> *root, std::string indent, bool last) {
    if (root != this->nil) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "     ";
        } else {
            std::cout << "L----";
            indent += "|    ";
        }

        std::string sColor = root->color == 'R' ? BOLDRED "RED" RESET
                                         : BOLDBLACK "BLACK" RESET;
        std::cout << root->key << "(" << sColor << ")" << std::endl;
        print_tree_debug_aux(root->left, indent, false);
        print_tree_debug_aux(root->right, indent, true);
    }
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::print_sorted_tree_debug(void) {
    print_sorted_tree_debug_aux(this->root);
}

template<RB_TREE_TEMPLATE>
void ft::red_black_tree<RB_TREE_TYPES>::print_sorted_tree_debug_aux(ft::rb_node<RB_NODE_TYPES> *node) {
    if (node != NULL) {
        print_sorted_tree_debug_aux(node->left);
        std::cout << "k: " << (node ? node->key : 0)
                  << " | p: " << (node->parent ? node->parent->key : 0)
                  << " | l: " << (node->left ? node->left->key : 0)
                  << " | r: " << (node->right ? node->right->key : 0)
                  << " | c: " << (node->color ? node->color : ' ')
                  << std::endl;
        print_sorted_tree_debug_aux(node->right);
    }
}
