#ifndef QUEUE
#define QUEUE
#include <iostream>

template<typename T, size_t N>
class Queue {
public:
    Queue() : m_front{-1}, m_rear{-1}, m_size{0} {
        m_arr = new T[N];
    }  
  
    ~Queue() {
        delete[] m_arr;
    }

public:

    bool isEmpty() {
        return m_front == -1;
    }

    bool isFull() {
        return (m_rear + 1) % N == m_front;  
    }

    void enqueue(T val) {
        if (isFull()) {
            std::cout << "Queue is full!!" << std::endl; 
            return;
        }
        if (isEmpty()) {
            m_front = m_rear = 0;
        } else {
            m_rear = (m_rear + 1) % N;
        }

        m_arr[m_rear] = val;
        std::cout << "Enqueued: " << val << std::endl;
        ++m_size;  
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        if (m_front == m_rear) {
            m_front = m_rear = -1;
        } else {
            m_front = (m_front + 1) % N;
        }
        --m_size;  
    }

    void print() {
        for (int i = m_front; i <= m_rear; ++i) {
            std::cout << m_arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int m_front;  
    int m_rear;
    int m_size;
    T* m_arr;
};

#endif // QUEUE

