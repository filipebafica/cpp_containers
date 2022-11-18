// Copyright (c) 2022 Filipe Báfica, Licensed under the MIT License.

#include <stack>
#include <iostream>

void default_constructor_test(void) {
    std::cout << "[DEFAULT CONSTRUCTOR TEST]" << std::endl;
    std::stack<int> s0;
    std::stack<float> s1;
    std::stack<char> s2;
}

void top_method_test(void) {
    std::cout << std::endl << "[TOP METHOD TEST]" << std::endl;
    std::stack<int> s0;

    s0.push(10);
    s0.push(11);
    s0.push(12);

    std::cout << "top of s0: " << s0.top() << std::endl;
}

void empty_method_test(void) {
    std::cout << std::endl << "[EMPTY METHOD TEST]" << std::endl;
    std::stack<int> s0;
    std::cout << "s0.empty(): " << s0.empty() << std::endl;
}

void size_method_test(void) {
    std::cout << std::endl << "[SIZE METHOD TEST]" << std::endl;
    std::stack<int> s0;

    s0.push(10);

    std::cout << "size of s0: " << s0.size() << std::endl;
}

void push_method_test(void) {
    std::cout << std::endl << "[PUSH METHOD TEST]" << std::endl;
    std::stack<int> s0;

    s0.push(10);

    std::cout << "top of s0: " << s0.top() << std::endl;
}

void pop_method_test(void) {
    std::cout << std::endl << "[POP METHOD TEST]" << std::endl;
    std::stack<int> s0;

    s0.push(10);
    s0.push(11);
    s0.pop();

    std::cout << "top of s0: " << s0.top() << std::endl;
}

int main(void) {
    default_constructor_test();
    top_method_test();
    empty_method_test();
    size_method_test();
    push_method_test();
    pop_method_test();
    return (0);
}
