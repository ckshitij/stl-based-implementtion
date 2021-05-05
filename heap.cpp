#include <iostream>
#include "heap.h"
using namespace std;

template<class T>
void mynamespace::Heap<T>::insertEle(T ele) {
    heap.push_back(ele);
    ++size;
    heapifyIns(size-1);
}

template<class T>
T mynamespace::Heap<T>::getTop() {
    if(heap.empty()) {
        throw myexception::my_exception("No elempty is present in heap");
    }
    return heap[0];
}

template<class T>
void mynamespace::Heap<T>::deleteEle(T ele) {
    int delInd;
    for(int i = 0 ; i < size; i++) {
        if(heap[i] == ele) {
            heap[i] = heap[size-1];
            break;
        }
    }
    --size;
    heap.resize(size);
    heapifyDel(0);
}

template<class T>
void mynamespace::Heap<T>::deleteRoot() {
    heap[0] = heap[size-1];
    --size;
    heap.resize(size);
    heapifyDel(0);
}

template<class T>
void mynamespace::Heap<T>::printHeap() {
    for(int i = 0 ; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    mynamespace::Heap<char> h("max");
    while(n--) {
        long q;
        char val;
        cin >> q;
        if(q < 3) {
            cin >> val;
            if (q == 1) { 
                h.insertEle(val);
            }
            else if (q == 2) { 
                h.deleteEle(val);
            }
        } else if(q == 3){
            char minAns = h.getTop();
            cout <<" top: element "<< minAns << endl;
        } else {
            h.printHeap();
        }
    }
    return 0;
}

