# CMakeLists.txt
cmake_minimum_required(VERSION 3.16.3)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
project(DataStructures)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#add_executable(${PROJECT_NAME} main.cpp)
# Add header only library
include_directories(datastructures)

enable_testing()

add_executable(
  dynamicArrayTest
  googletest/dynamicArrayTest.cpp
)
target_link_libraries(
  dynamicArrayTest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(dynamicArrayTest)

add_executable(
  listTest
  googletest/listTest.cpp
)
target_link_libraries(
  listTest
  gtest_main
)

gtest_discover_tests(listTest)

add_executable(
  doublyLinkedListTest
  googletest/doublyLinkedListTest.cpp
)
target_link_libraries(
  doublyLinkedListTest
  gtest_main
)

gtest_discover_tests(doublyLinkedListTest)