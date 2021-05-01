#ifndef K_QUEUE_H
#define K_QUEUE_H

#include "myexception.h"
#include <stddef.h>
#define INT_MAX 2147483647

namespace mynamespace {

    template<class T>
    struct QueueNode
    {
        T data;
        QueueNode* prev;
        QueueNode* next;
        QueueNode(T data) {
            this->data = data;
            prev = next = nullptr;
        }
    };

    template<class T>
    class queue {
        QueueNode<T> *head;
        QueueNode<T> *rear;
        int size_q;
        int capacity;
    public:
        queue<T>& operator=(queue<T> &o);
        queue();
        queue(int capacity);
        queue(queue<T> &o);
        T front();
        void push(T data);
        void pop();
        T back();
        int size();
        bool empty();
        QueueNode<T> *begin() {
            return this->rear;
        }

        QueueNode<T> *end() {
            return this->head;
        }
    };
    

}

#endif //K_QUEUE_H
