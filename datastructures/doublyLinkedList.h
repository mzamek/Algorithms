// Doubly Linked list - modern C++ implementation
#ifndef DOUBLY_LINED_LIST_H
#define DOUBLY_LINED_LIST_H
#include<stdexcept>

namespace dataStructures
{
    template <typename T>
    class node
    {
        public:
            T value;
            node<T>* next;
            node<T>* last;
            node() : next(nullptr), last(nullptr) {}
            node(const T& val) : next(nullptr), last(nullptr), value(val) {}
        
    };

    template <typename T>
    class doublyLinkedList
    {
        private:

            size_t _size;
        public:
            node<T>* head;
            node<T>* tail;
            doublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}
            doublyLinkedList(const T& val) : head(nullptr), tail(nullptr), _size(0) 
            {
                push_front(val);
            }
            doublyLinkedList(T&& val) : head(nullptr), tail(nullptr), _size(0) 
            {
                node<T>* tmp = new node<T>();
                tmp->value=std::move(val);
                tmp->next=head;
                if(head!=nullptr){
                    head->next->last=tmp;
                } else {
                    tail=tmp;
                }
                head=tmp;
                _size++;
            }
            T& operator[](size_t index)
            {
                node<T>* tmp=head;
                if(head==nullptr)
                {
                    throw std::out_of_range("index out of bounds");
                } else {
                    
                    for(int i=0;i<index;i++){
                        tmp=tmp->next;
                        if(tmp==nullptr){
                            throw std::out_of_range("index out of bounds");
                        }
                    }
                }
                return tmp->value;
            }

            void push_front(const T& val)
            {
                node<T>* tmp = new node<T>(val);
                if(head==nullptr){
                    tail=tmp;
                } else {
                    head->last=tmp;
                    tmp->next=head;
                }
                head=tmp;
                _size++;
            }
            void push_back(const T& val)
            {
                node<T>* tmp = new node<T>(val);
                if(tail==nullptr){
                    head=tmp;
                } else {
                    tmp->last=tail;
                    tmp->last->next=tmp;
                }
                tail=tmp;
                _size++;
            }
            void pop_front()
            {
                if(head!=nullptr){
                    node<T>* tmp=head;
                    if(head==tail)
                    {
                        head=nullptr;
                        tail=nullptr;
                    } else {
                        head=head->next;
                        head->last=nullptr;
                    }
                    delete tmp;
                    _size--;
                }
            }
            void pop_back()
            {
                if(tail!=nullptr){
                    node<T>* tmp = tail;
                    if(tail==head){
                        tail=nullptr;
                        head=nullptr;
                    } else {
                        tail=tail->last;
                        tail->next=nullptr;
                    }
                    delete tmp;
                    _size--;
                }
            }
            void clear()
            {
                while(size()>0)
                {
                    pop_front();
                }
            }
            size_t size()
            {
                return _size;
            }

            void erase(const size_t p){
                if(p>=size()){
                    throw std::out_of_range("doublyLinkedList delete out of range");
                } else if(p==0){
                    pop_front();
                } else if(p==size()-1){
                    pop_back();
                } else {
                    node<T>* n=head;
                    for(int i=0;i<p;i++){
                        n=n->next;
                    }
                    n->next->last=n->last;
                    n->last->next=n->next;
                    delete n;
                    _size--;
                }
            }
            //inserts after element starfting at 0;
            void insert(const size_t p, const T& val){
                if(p>size()){
                    throw std::out_of_range("insert out of range");
                } else {
                    if(p==0){
                        push_front(val);
                    } else if(p==size()){
                        push_back(val);
                    } else {
                        node<T>* newNode = new node<T>(val);
                        node<T>* insertAt=head;
                        for(int i=0;i<p;i++){
                            insertAt=insertAt->next;
                        }

                        newNode->next=insertAt;
                        newNode->last=insertAt->last;
                        newNode->next->last=newNode;
                        newNode->last->next=newNode;
                        _size++;
                    }
                }
            }
    };
}
#endif