#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector{
public:
  Vector(){
    m_size = 0;
    m_copasity = 2;  
    m_vector = new T[m_copasity];
  }
  ~Vector(){
    delete[] m_vector;
}
  Vector(const Vector& rhs){
    m_size = rhs.m_size;
    m_copasity = rhs.m_copasity;
    m_vector = new T[rhs.m_copasity];

    for(int i = 0; i < m_size; ++i){
        m_vector[i] = rhs.m_vector[i];
    }
}
  Vector& operator=(const Vector& rhs) {
    if(this != &rhs){
       m_size = rhs.m_size;
       m_copasity = rhs.m_copasity;
       m_vector = new T[rhs.m_copasity];

      for(int i = 0; i < m_size; ++i){
        m_vector[i] = rhs.m_vector[i];
       }
    }
    return *this;
}

public:
  
  void push_back(T elem){
    if(m_copasity == m_size){
        m_resize();
    }

    m_vector[m_size] = elem;
    ++m_size;
}

  int get_size(){
    return m_size;
  }

  T at(int position){
    return m_vector[position];
  }
  
  void pop(){
    --m_size;
  }


  void push_front(T elem){
     if(m_copasity == m_size){
        m_resize();
    }

     for (int i = m_size; i > 0; --i) {
        m_vector[i] = m_vector[i - 1];
     }

      m_vector[0] = elem;
      ++m_size;
  }


  void pop_front(){
    for (int i = 0; i < m_size; ++i) {
        m_vector[i] = m_vector[i + 1];
      }
  --m_size;
  }


  void insert(int position, T elem){
    if(m_copasity == m_size){
        m_resize();
    }

    for(int i = m_size; i <position; --i){
        m_vector[i] = m_vector[i - 1];
    }

    m_vector[position] = elem;
    ++m_size;
  }


  void remove(int position){
     for(int i = position; i < m_size; ++i){
        m_vector[i] = m_vector[i+1];
     }
    
    --m_size;
  }


  void erase(){
    delete[] m_vector
    m_size = 0;
    m_copasity = 0;
  }

  void print(){
    for(int i = 0; i < m_size; ++i){
        std::cout<<Vector::at(i)<<std::endl;
    }
  }

private:
  int m_size;
  int m_copasity;
  T * m_vector;
private:
  void m_resize(){
     m_copasity *= 2;
       T * tmp = new T[m_copasity];
       for(int i = 0; i < m_size; ++i){
        tmp[i] = m_vector[i];
       }

       delete[] m_vector;
       m_vector = tmp;
       tmp = nullptr;
  }
};


#endif // VECTOR_H