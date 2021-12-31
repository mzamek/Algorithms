#include <gtest/gtest.h>
#include <dynamicArray.h>
// Demonstrate some basic assertions.
TEST(dynamicArrayTest, constructorTest) {
  // Expect two strings not to be equal.
  dataStructures::dynamicArray<int> intArray;
  dataStructures::dynamicArray<bool> boolArray(1);
  //dynamicArray<float> floatArray;

  EXPECT_EQ(intArray.getSize(), 0);
  EXPECT_EQ(boolArray.getSize(), 0);
  // Expect equality.
}