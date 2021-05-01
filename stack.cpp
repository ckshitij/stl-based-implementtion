#include <iostream>
#include "stack.h"

template<class T>
int mynamespace::stack<T>::size() {
    return this->size_t;
}

template<class T>
mynamespace::stack<T>::stack(stack<T> &val) {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_t = 0;
    this->capacity = val.capacity;
    for(StackNode<T> *temp = val.rear; temp != nullptr; temp = temp->next) {
        this->push(temp->data);
    }
}

template<class T>
mynamespace::stack<T>& mynamespace::stack<T>::operator=(stack<T> &val) {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_t = 0;
    this->capacity = val.capacity;
    for(StackNode<T> *temp = val.rear; temp != nullptr; temp = temp->next) {
        std::cout << temp->data << std::endl;
        this->push(temp->data);
    }
    return this;
}

template<class T>
mynamespace::stack<T>::stack() {
    head = nullptr;
    rear = nullptr;
    size_t = 0;
    capacity = INT_MAX;
}

template<class T>
mynamespace::stack<T>::stack(int capacity) {
    this->head = nullptr;
    this->rear = nullptr;
    this->size_t = 0;
    this->capacity = capacity;
}

template<class T>
void mynamespace::stack<T>::push(T data) {
    if(capacity < 1 || size_t > capacity ) 
        throw myexception::my_exception("stack Overflow");
    StackNode<T>* newNode = new StackNode<T>(data); 
    if(!head) {
        head = newNode;
        rear = head;
        ++size_t;
        return;
    }
    newNode->next = head;
    head = newNode;
    ++size_t;
}

template<class T>
void mynamespace::stack<T>::pop() {
    if(empty())
        throw myexception::my_exception("Empty Stack");
    if (!head) {
        return;
    };
    StackNode<T>* temp = head;
    head = head->next;
    free(temp);
    --size_t;
}

template<class T>
T mynamespace::stack<T>::top() {
    if(!head) {
        throw myexception::my_exception("Empty Stack");
    }
    return head->data;
}

template<class T>
bool mynamespace::stack<T>::empty() {
    if(!head || size_t == 0) 
        return true; 
    return false;
}

int main() {
    mynamespace::stack<std::string> st;
   
    try {
        st.push("hello1");
        st.push("world");
        st.push("kshitij");
        st.push("chaurasiya");

        mynamespace::stack<std::string> st2 = st;
        
        while(!st.empty()) {
            std::cout << "Stack size: " << st.size()  << " : " << st.top() << std::endl;
            st.pop();
        }

        while(!st2.empty()) {
            std::cout << "Stack size: " << st2.size()  << " : " << st2.top() << std::endl;
            st2.pop();
        }
        
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "exception is thrown" << std::endl;
    }
    return 0;
}