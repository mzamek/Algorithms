#include <gtest/gtest.h>
#include <dynamicArray.h>
#include <iostream>
#include<vector>
// Demonstrate some basic assertions.
TEST(dynamicArrayTest, constructorTest) {
  // Expect two strings not to be equal.
  dataStructures::dynamicArray<int> intArray;
  dataStructures::dynamicArray<bool> boolArray(1);
  dataStructures::dynamicArray<char*> charArray(100);


  EXPECT_EQ(intArray.getSize(), 0);
  EXPECT_EQ(boolArray.getSize(), 0);
  EXPECT_EQ(charArray.getSize(), 0);
  // Expect equality.
}

TEST(dynamicArrayTest, MaxSizeTest) {
  // Expect two strings not to be equal.
  // initialize to big capacity

  dataStructures::dynamicArray<int> intArray(100);

  for(long long i=0; i< USHRT_MAX ; i++ )
  {

    ASSERT_EQ(intArray.getSize(), i) << "getSize() before insert at i = "<< i;
    ASSERT_TRUE(intArray.insertBack((int)i)) << "insertBack() at i = "<< i;
    ASSERT_EQ(intArray.getSize(), i+1) << "getSize() after insert at  i = "<< i;
    ASSERT_EQ(intArray[i],(int)i) << "[] after insert at  i = "<< i;;
  }
  // reached maximum capacity
  ASSERT_EQ(intArray.getSize(), USHRT_MAX);
  for(int i=0; i< 10; i++){
    ASSERT_FALSE(intArray.insertBack(0));
    ASSERT_EQ(intArray.getSize(), USHRT_MAX);
  }
  for(long long i=USHRT_MAX; i> 0 ; i-- )
  {
    ASSERT_EQ(intArray.getSize(), i);
    ASSERT_TRUE(intArray.removeBack());
  }
  // array empty
  //std::cout<< "SIZE: " <<intArray.getSize() << std::endl;
    for(int i=0; i< 10; i++){
    ASSERT_FALSE(intArray.removeBack());
    ASSERT_EQ(intArray.getSize(), 0);
  }
}
TEST(dynamicArrayTest, insertAndRemoveTest) {
  dataStructures::dynamicArray<int> intArray;
  std::vector<int> vec;

  // populate array
  for(int i=0; i<1000; i++){
    vec.push_back(i);
    intArray.insertBack(i);
  }
  int randIdx;
  for(int i=0; i<1000; i++){
    randIdx = rand() % vec.size();
    ASSERT_TRUE(intArray.removeAt(randIdx));
    vec.erase(vec.begin()+randIdx);
    ASSERT_EQ(vec.size(), intArray.getSize());
    for(int j=0;j<vec.size();j++){
      ASSERT_EQ(vec[j],intArray[j]);
    }

  }
  ASSERT_EQ(intArray.getSize(), 0);
}