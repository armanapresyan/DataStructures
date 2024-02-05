#ifndef SINGLELINKEDLIST_HPP
#define SINGLELINKEDLIST_HPP

#include <iostream>

template<typename T>
class SingleLinkedList {
public:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value{val}, next{nullptr} {}
        ~Node(){
            if(next != nullptr){
                delete next;
            }
        }
    };

    SingleLinkedList() : head{nullptr}, size{} {}

    ~SingleLinkedList() {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
    }

    void push_back(T elem) {
        Node* node = new Node(elem);
        if (head == nullptr) {
            head = node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        ++size;
    }

    Node* getHead() {
    return head;
    }

    void push_front(T value){
       Node* node = new Node(value);
       if(head == nullptr){
         head = node;
       }
       node->next = head;
       head = node;
       ++size;
    }

   void pop_back() {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        size = 0;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    --size;
}

void pop_front() {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        size = 0;
        return;
    }

    Node* temp = head;
    head = head->next;
    --size;
    delete temp;
}
   
   T search(T value){
    Node* current = head;
    while(current->next != nullptr){
        if(current->value == value){
            return value;
        }
        current = current->next;
    }
    return T();
   }

   void insert(int position, T value){
    if(position == 0){
        push_front(value);
    }else if(size  == position){
        push_back(value);
    }else{
       Node* node = new Node(value);
       Node* current = head;
       for(int i = 0; i < position - 1 && current != nullptr; ++i){
          current = current->next;
       }
       node->next = current->next->next;
       current->next = node;
       ++size;
    }

   }
   
int get_size(){
    return size;
}
 
   void insert(int position, const SingleLinkedList<T>& list){
    if(position == 0){
        Node* current = list.head;
        while(current->next != nullptr){
            push_front(current->value);
             current = current->next;
        }
    }else if(size  == position){
        Node* current = list.head;
        while(current->next != nullptr){
            push_back(current->value);
             current = current->next;
        }
    }else{
        Node* current = list.head;
        int currentPosition = position;
        while (current != nullptr) {
            insert(currentPosition, current->value);
            current = current->next;
            currentPosition++;
        }
    }
   }

   void deleteNode(int position){
     if(position == 0){
      pop_front();
     }else if(size == position){
        pop_back();
     }else{
        Node* current = head;
       for(int i = 0; i < position - 1 && current != nullptr; ++i){
          current = current->next;
       }
       Node* tmp = current->next;
       current->next = current->next->next;
       --size;
       delete tmp;
     }
   }

  void reverse(){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while(current != nullptr){
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
     head = prev; 
  }

  Node* getMiddleNode(){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
  }

  Node* hasCycle(){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
           break;
        }
    }
    if(fast == nullptr || fast->next == nullptr){
       return nullptr;
    }
    return slow;
  }

   

    void printNode() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    int size;
};

#endif // SINGLELINKEDLIST_HPP
