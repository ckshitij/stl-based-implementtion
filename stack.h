#ifndef K_STACK_H
#define K_STACK_H

#include "myexception.h"
#include <stddef.h>
#define INT_MAX 2147483647

namespace mynamespace {

    template<typename T>
    struct StackNode {
        T data;
        StackNode *next;

        StackNode(T val) {
            data = val;
            next = nullptr;
        }
    };


    template<class T>
    class stack {
        StackNode<T> *head;
        StackNode<T> *rear;
        int size_t;
        int capacity;

    public:

        stack<T>& operator=(stack<T> &ob);
        stack(stack<T> &ob);
        stack();
        int size();
        stack(int capacity);
        void push(T data);
        void pop();
        T top();
        bool empty();
    };

}
#endif //K_STACK_H
