#include <gtest/gtest.h>
#include <doublyLinkedList.h>
#include <iostream>
#include<vector>

TEST(doublyLinkedListTest, constructorTest) {
    dataStructures::doublyLinkedList<int> intList;
    dataStructures::doublyLinkedList<std::string> sList("blah");
    EXPECT_EQ(intList.head, nullptr);
    EXPECT_EQ(intList.tail, nullptr);
    EXPECT_EQ(sList.head->value, std::string("blah"));
    EXPECT_EQ(sList.head->next,nullptr);
    EXPECT_EQ(sList.head->last,nullptr);
    EXPECT_EQ(sList.head,sList.tail);
    sList.clear();
    EXPECT_EQ(sList.head,nullptr);
     EXPECT_EQ(sList.tail,nullptr);   
}
TEST(doublyLinkedListTest, pushBackTest) {
    dataStructures::doublyLinkedList<int> intList;
    std::vector<int> vec;
    for(int i=0; i<10; i++){
        vec.push_back(i);
        intList.push_back(i);
        EXPECT_EQ(vec.size(),intList.size());
        EXPECT_EQ((intList.head)->last, nullptr);
        EXPECT_EQ((intList.tail)->next, nullptr);
    }
    for(int i=0; i<vec.size(); i++){
        EXPECT_EQ(vec[i], intList[i]);
    }
    dataStructures::node<int>* tmp=intList.tail;
    int idx=intList.size();
    while (tmp!=nullptr){
      idx--;
      EXPECT_EQ(tmp->value,vec[idx]);
      tmp=tmp->last;
    }
    EXPECT_EQ(idx, 0);
    for(int i=0; i<10; i++){
        vec.pop_back();
        intList.pop_back();
        EXPECT_EQ(vec.size(), intList.size());
    }
    EXPECT_EQ(intList.head, nullptr);
    EXPECT_EQ(intList.tail, nullptr);    
}


TEST(doublyLinkedListTest, pushFrontTest) {
    dataStructures::doublyLinkedList<int> intList;
    std::vector<int> vec;
    for(int i=0; i<10; i++){
        vec.insert(vec.begin(),i);
        intList.push_front(i);
        EXPECT_EQ(vec.size(),intList.size());
        EXPECT_EQ((intList.head)->last, nullptr);
        EXPECT_EQ((intList.tail)->next, nullptr);
    }
    
    for(int i=0; i<vec.size(); i++){
        EXPECT_EQ(vec[i], intList[i]);
    }
    
    dataStructures::node<int>* tmp=intList.tail;
    int idx=vec.size();
    while (tmp!=nullptr){
      idx--;
      EXPECT_EQ(tmp->value,vec[idx]);
      tmp=tmp->last;
    }
    EXPECT_EQ(idx, 0);
    
    for(int i=0; i<10; i++){
        vec.erase(vec.begin());
        intList.pop_front();
        EXPECT_EQ(vec.size(), intList.size());
    }
    EXPECT_EQ(intList.head, nullptr);
    EXPECT_EQ(intList.tail, nullptr); 
      
}
TEST(doublyLinkedListTest, insertTest) {
    dataStructures::doublyLinkedList<int> intList;
    std::vector<int> vec;
    int randIdx;
    vec.insert(vec.begin(),0);
    intList.insert(0,0);
    EXPECT_EQ(vec.size(),intList.size());

    
    for(int i=0; i<50; i++){
      randIdx = rand() % vec.size();
      vec.insert(vec.begin()+randIdx,i);
      intList.insert(randIdx,i);
      EXPECT_EQ(vec.size(),intList.size());
      EXPECT_EQ((intList.head)->last, nullptr);
      EXPECT_EQ((intList.tail)->next, nullptr);
    }
    for(int i=0; i<vec.size(); i++){
        EXPECT_EQ(vec[i], intList[i]);
    }
    while(vec.size()>1){
      
      randIdx = rand() % vec.size();

      vec.erase(vec.begin()+randIdx);
      intList.erase(randIdx);
      EXPECT_EQ(vec.size(),intList.size());
      EXPECT_EQ((intList.head)->last, nullptr);
      EXPECT_EQ((intList.tail)->next, nullptr);
      for(int i=0; i<vec.size(); i++){
        EXPECT_EQ(vec[i], intList[i]);
      }
    }
    intList.erase(0);
    EXPECT_EQ(intList.size(),0);
    EXPECT_EQ(intList.head, nullptr);
    EXPECT_EQ(intList.tail, nullptr);                  
}