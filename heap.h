#ifndef K_HEAP_H
#define K_HEAP_H

#include "myexception.h"
#include <vector>
#include <string>

// there are 3 method 
// 1 inseart element in heap;
// 2 delete specific method from heap;
// 3 get top element from heap;
// By defualt it will act as min heap 
// For converting it to max heap just pass //Heap<char> h("max") or h("greater");

namespace mynamespace {

    template<class T>
    class Heap {
        std::vector<T> heap;
        int size;
        char op;
        int parentInd(int ele) {
            return (ele -1)/2;
        }
        
        int left(int ele) {
            return 2*ele + 1;
        }
        
        int right(int ele) {
            return 2*ele + 2;
        }

        bool compareFun(T a, T b) {
            if(this->op == '<') {
                return a < b;
            }
            return a > b;
        }
        
        void heapifyIns(int pos) {
            int parent = parentInd(pos);
            if(parent >= 0) {
                if(compareFun(heap[parent], heap[pos])) {
                    std::swap(heap[parent], heap[pos]);
                    heapifyIns(parent);
                }
                return;
            }
            return;
        }

        void heapifyDel(int pos) {
            int curr = pos;
            if(left(curr) < size && compareFun(heap[curr], heap[left(curr)])) {
                curr = left(curr);
            }
            if(right(curr) < size && compareFun(heap[curr], heap[right(curr)])) {
                curr = right(curr);
            }
            if(pos != curr) {
                std::swap(heap[curr], heap[pos]);
                heapifyDel(curr);
            }
        }
        
    public:
        Heap() {
            size = 0;
            this->op = '>';
        }

        Heap(std::string com) {
            size = 0;
            if(com == "greater" || com == "max") {
                this->op = '<';
            }
        }
        void insertEle(T val);
        void deleteEle(T val);
        void deleteRoot();
        void printHeap();
        T getTop(); 
    };
    

}

#endif //K_HEAP_H
