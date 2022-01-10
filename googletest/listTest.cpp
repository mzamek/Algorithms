#include <gtest/gtest.h>
#include <list.h>
#include <iostream>
#include<vector>

TEST(listTest, constructorTest) {
    dataStructures::list<int> intList;
    EXPECT_EQ(intList.head, nullptr);
}