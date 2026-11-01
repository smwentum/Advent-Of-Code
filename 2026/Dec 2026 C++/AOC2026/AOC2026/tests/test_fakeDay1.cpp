#include <gtest/gtest.h>

#include<vector>

#include "../src/Includes/fakeDay1.h"

using namespace std; 

// A simple function to demonstrate testing
int add(int a, int b) {
    return a + b;
}

// TEST(TestSuiteName, TestName)
TEST(AdditionTests, HandlesPositiveInputs) {
    EXPECT_EQ(add(1, 2), 3);
}

TEST(AdditionTests, HandlesNegativeInputs) {
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(AdditionTests, HandlesMixedPositiveAndNegativeInputs) {
    EXPECT_EQ(add(-1, 1), 0);
}
TEST(AdditionTests, HandlesAllZeros) {
    EXPECT_EQ(add(0, 0), 0);
}

TEST(FakeDayTests, HandlesSampleInput) 
{
    vector<int> v1{1, 2, 3}; 
    vector<int> v2{ 1, 2, 3 };
    EXPECT_EQ(DayOnePartOneAnswer(v1, v2), 0);
}


TEST(FakeDayTests, HandlesSampleInput1)
{
    vector<int> v1{ 1, 2, 3 };
    vector<int> v2{ 1, 2, 4 };
    EXPECT_EQ(DayOnePartOneAnswer(v1, v2), 1);
}

TEST(FakeDayTests, HandlesSampleInput2)
{
    vector<int> v1{ 3, 4, 2,1,3,3 };
    vector<int> v2{ 4, 3, 5,3,9,3 };
    EXPECT_EQ(DayOnePartOneAnswer(v1, v2), 11);
}

TEST(FakeDayTests, HandlesSamplePartTwoInput1)
{
    vector<int> v1{ 3, 4, 2,1,3,3 };
    vector<int> v2{ 4, 3, 5,3,9,3 };
    EXPECT_EQ(DayOnePartOneAnswer(v1, v2), 11);
}