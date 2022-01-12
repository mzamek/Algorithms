#include <gtest/gtest.h>
#include <doublyLinkedList.h>
#include <iostream>
#include<vector>

TEST(doublyLinkedListTest, constructorTest) {
    dataStructures::doublyLinkedList<int> intList;
    dataStructures::doublyLinkedList<std::string> sList("blah");
    EXPECT_EQ(intList.head, nullptr);
    EXPECT_EQ(sList.head->value, std::string("blah"));
    EXPECT_EQ(sList.head->next,nullptr);
    sList.clear();
    EXPECT_EQ(sList.head,nullptr);
}
TEST(doublyLinkedListTest, pushBackTest) {
    dataStructures::doublyLinkedList<int> intList;
    std::vector<int> vec;
    for(int i=0; i<10; i++){
        vec.push_back(i);
        intList.push_back(i);
    }
    dataStructures::node<int>* tmp=intList.head;
    dataStructures::node<int>* last;    
    for(int i=0; i<10; i++){
        last=tmp;
        EXPECT_EQ(tmp->value,vec[i]);
        tmp=tmp->next;
    }
    EXPECT_EQ(tmp,nullptr);
    EXPECT_EQ(last->value,9);
    for(int i=0; i<10; i++){
        intList.pop_front();
        vec.erase(vec.begin());
        tmp=intList.head;
        for(int j=0; j<vec.size();j++){
            EXPECT_EQ(intList[j],vec[j]);
        }
    }
    EXPECT_EQ(intList.head, nullptr);
}


TEST(doublyLinkedListTest, pushFrontTest) {
    dataStructures::doublyLinkedList<int> intList;
    std::vector<int> vec;
    for(int i=0; i<10; i++){
        vec.insert(vec.begin(), i);
        intList.push_front(i);
    }
    for(int j=0; j<vec.size();j++){
        EXPECT_EQ(intList[j],vec[j]);
    }
    for(int i=0; i<10; i++){
        intList.pop_back();
        vec.pop_back();
        for(int j=0; j<vec.size();j++){
            EXPECT_EQ(intList[j],vec[j]);
        }
    }
    EXPECT_EQ(intList.head, nullptr);
    //std::cout << "intList.head->next:" << intList.head->next << std::endl;
}