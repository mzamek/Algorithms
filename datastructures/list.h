// Linked list - modern C++ implementation

#ifndef LIST_H
#define LIST_H
#include<stdexcept>

namespace dataStructures
{
    template<class T>
    class node {
        public:
            T value;
            node<T>* next;
    };

    template<class N>
    class list {
        public:
            N& operator[](unsigned int index)
            {
                node<N>* tmp=head;
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
            node<N>* head;
            list(): head(nullptr) {}
            list(const N& data) {
                head=new node<N>;
                head->value=data;
                head->next=nullptr;
            }
            list(N&& data) {
                head=new node<N>;
                head->value=std::move(data);
                head->next=nullptr;
            }
            ~list(){
                clear();
            }
            void clear(){
                while(head!=nullptr){
                    node<N>* tmp;
                    tmp=head;
                    head=head->next;
                    delete tmp;
                }
            }
            void push_front(const N& data){
                node<N>* tmp;
                tmp = new node<N>;
                tmp->value=data;
                tmp->next=head;
                head=tmp;
            }
            void push_back(const N& data){
                node<N>* tmp;
                if(head==nullptr){
                    tmp=new node<N>;
                    tmp->next=nullptr;
                    tmp->value=data;
                    head=tmp;
                } else {
                    tmp=head;
                    while(tmp->next!=nullptr){
                        tmp=tmp->next;
                    }
                    tmp->next=new node<N>;
                    tmp->next->value=data;
                    tmp->next->next=nullptr;    
                }
            }

            void pop_front(){
                if(head==nullptr){
                    return;
                } else{
                    node<N>* tmp;
                    tmp=head;
                    head=head->next;
                    delete tmp;
                }
            }
            void pop_back(){
                if(head==nullptr){
                    return;
                } else if(head->next==nullptr){
                    delete head;
                    head=nullptr;
                } else {
                    node<N>* tmp=head;
                    while(tmp->next->next!=nullptr){
                        tmp=tmp->next;
                    }
                    delete tmp->next;
                    tmp->next=nullptr;
                }
                return;
            }
    };

}
#endif
