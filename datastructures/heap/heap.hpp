#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdexcept> 
#include <algorithm>


template<typename T>
class Heap{

public:
   Heap(T* arr, int size) : m_arr{arr}, m_heapsize{size} {}

public:
   int parent(int i) {
    if (i >= m_heapsize || i < 0) {
        throw std::out_of_range("Index out of bounds");
    }
    return i / 2;
  }

 int left(int i) {
    int leftIndex = 2 * i;
    if (leftIndex >= m_heapsize || leftIndex < 0) {
        throw std::out_of_range("Index out of bounds");
    }
    return leftIndex;
}

int right(int i) {
    int rightIndex = 2 * i + 1;
    if (rightIndex >= m_heapsize || rightIndex < 0) {
        throw std::out_of_range("Index out of bounds");
    }
    return rightIndex;
}


  void maxHeapify(int i){
     int leftIndex = left(i);
     int rightIndex = right(i);
     int largest = i;
     if(leftIndex < m_heapsize && m_arr[i] < m_arr[leftIndex]){
        largest = leftIndex;
     } 
     if(rightIndex < m_heapsize && m_arr[largest] < m_arr[rightIndex]){
        largest = rightIndex;
     }

     if(largest != i){
        std::swap(m_arr[i], m_arr[largest]);
        maxHeapify(largest);
     }
  }

 void buildMaxHeap(int size){
    for(int i = size / 2 - 1; i >= 0; --i){
        maxHeapify(i);  
    }
}

  void heapSort(int size){
    buildMaxHeap(size);
    int n = size - 1;  
    for(int i = n; i >= 1; --i){  
        std::swap(m_arr[0], m_arr[i]);
        maxHeapify(0);
    }
}


private:
   T* m_arr;
   int m_heapsize;
};





#endif //HEAP_HPP