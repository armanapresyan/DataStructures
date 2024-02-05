#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

template<typename T>
class Doublelinkedlist{
public:
  struct Node{
         T val;
         Node* next;
         Node* prev;
         Node(T v) : val{v}, next{nullptr}, prev{nullptr} {} 
    };

public:
  Doublelinkedlist() : size(0), head(nullptr), tail(nullptr) {}
 ~Doublelinkedlist() {
    while (head != nullptr) {
        Node* temp = head;  
        head = head->next;  
        delete temp;  
    }
}
  

public:
   void push_back(T value){
     Node* node = new Node(value);
     if(head == nullptr){
        head = node;
        tail = node;
     }else{
        tail->next = node;
        node->prev = tail;
        tail = node;
     }
     ++size;   
}
   void push_front(T value){
    if(head == nullptr){
      push_back(value);
    }
    Node* node = new Node(value);
    node->next = head; 
    node->prev = nullptr;
    head->prev = node;
    head = node;
    ++size;

}
   void insert(int index, T value){
    if(index == 0){
        push_front(value);
    }else if(index == size - 1){
        push_back(value);
    }else if(index > 0 && index < size){
      
       Node* node = new Node(value);
       Node* current = head;
       
       for(int i = 0; i < index - 1; ++i){
          current = current->next;
       }
        node->prev = current;
        node->next = current->next;
        current->next = node;
        current->next->prev = node;
        ++size;
    }else{
        std::cout<<"Invalid index"<<std::endl;
    }

}
   void remove(int index){
    
    if(index == 0){
       Node* first = head;
       first->next->prev = nullptr;
       head = first->next;
       delete first;
       --size;
    }else if(index == size - 1){
        Node* last = tail;
        last->prev->next = nullptr;
        tail = last->prev;
        delete last;
        --size;
    }else if(index > 0 && index < size){
      
       Node* current = head;
       
       for(int i = 0; i < index; ++i){
          current = current->next;
       }
       current->prev->next = current->next;
       current->next->prev = current->prev;
       delete current;
       --size;
    }else{
        std::cout<<"Invalid index"<<std::endl;
    }
}
   int get(int index) {
    Node* current = head;
    for(int i = 0; i < index; ++i){
        current = current->next;
    }
    return current->val;
}

   int get_size(){
    return size;
}


   void printList(){
      while(head != nullptr){
        std::cout<<head->val<<" ";
        head = head->next;
      }

}

   void printReverse(){
    while(tail != nullptr){
        std::cout<<tail->val<<" ";
        tail = tail->prev;
    }
}

   void traverse(void (*ptr)(int val)){
   Node* current = head;
    while(current != nullptr){
        ptr(current->val);
        current = current->next;
    }
}

void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

           
            current = current->prev;
        }

        
        if (temp != nullptr) {
            head = temp->prev;
            tail = current;  
        }
    }

      void insertionSort() {
        if (size <= 1) {
            return;
        }

        Node* sorted = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;

            if (!sorted || sorted->val >= current->val) {
                current->next = sorted;
                current->prev = nullptr;
                if (sorted) {
                    sorted->prev = current;
                }
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->val < current->val) {
                    temp = temp->next;
                }
                current->next = temp->next;
                current->prev = temp;
                if (temp->next) {
                    temp->next->prev = current;
                }
                temp->next = current;
            }

            current = next;
        }

        head = sorted;

        while (sorted && sorted->next) {
            sorted = sorted->next;
        }
        tail = sorted;
    }

private:
    int size;
    Node* head;
    Node* tail;
    
};

#endif // DOUBLELINKEDLIST_HPP