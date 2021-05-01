#include <iostream>
#include "queue.h"

template<class T>
int mynamespace::queue<T>::size() {
    return this->size_q;
}

template<class T>
mynamespace::queue<T>::queue(queue<T> &val) {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_q = 0;
    this->capacity = val.capacity;
    for(QueueNode<T> *temp = val.rear; temp != nullptr; temp = temp->next) {
        push(temp->data);
    }
}

template<class T>
mynamespace::queue<T>& mynamespace::queue<T>::operator=(queue<T> &val) {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_q = 0;
    this->capacity = val.capacity;
    for(QueueNode<T> *temp = val.rear; temp != nullptr; temp = temp->next) {
        this->push(temp->data);
    }
    return this;
}

template<class T>
mynamespace::queue<T>::queue() {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_q = 0;
    this->capacity = INT_MAX;
}

template<class T>
mynamespace::queue<T>::queue(int capacity) {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_q = 0;
    this->capacity = capacity;
}

template<class T>
bool mynamespace::queue<T>::empty() {
    if((!head && (head == rear)) || size_q == 0) 
        return true; 
    return false;
}

template<class T>
void mynamespace::queue<T>::push(T data) {
    if(this->capacity < 0 || this->size_q > this->capacity) {
        throw myexception::my_exception("Queue Overflow");
    }

    if(!head && (head == rear)) {
        head = new QueueNode<T>(data);
        rear = head;
        ++this->size_q;
    } else {
        QueueNode<T> *temp = new QueueNode<T>(data);
        head->next = temp;
        temp->prev = head;
        head = temp;
        ++this->size_q;
    }
}

template<class T>
void mynamespace::queue<T>::pop() {
    if(empty()) {
        throw myexception::my_exception("Empty Queue");
    }

    if(!rear) return;
    QueueNode<T> *temp = rear;
    rear = rear->next;
    if(rear)
        rear->prev = nullptr;
    delete(temp);
    --this->size_q;
}

template<class T>
T mynamespace::queue<T>::front() {
    if(!rear) {
        throw myexception::my_exception("No front : Empty Queue");
    }
    return rear->data;
}

template<class T>
T mynamespace::queue<T>::back() {
    if(!head) {
        throw myexception::my_exception("No back : Empty Queue");
    }
    return head->data;
}

int main() {
    mynamespace::queue<std::string> st;
    
    try {
        st.push("hello1");
        st.push("world1");
        st.push("kshitij1");
        st.push("chaurasiya1");

        mynamespace::queue<std::string> st2 = st;
        
        std::cout << "Queue size: " << st.size()  << " begin: " << st.begin() << " end: " << st.end() << std::endl;
        std::cout << "Queue size: " << st2.size()  << " begin: " << st2.begin() << " end: " << st2.end() << std::endl;

        while(!st.empty()) {
            std::cout << "Queue size: " << st.size()  << " front: " << st.front() << " back: " << st.back() << std::endl;
            st.pop();
       }
        while(!st2.empty()) {
            std::cout << "st2 Queue size: " << st2.size()  << " front: " << st2.front() << " back: " << st2.back() << std::endl;
            st2.pop();
        }
        
        
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "exception is thrown" << std::endl;
    }
    return 0;
}