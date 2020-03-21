#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ulamspiral.hpp"


TEST(ulamspiral, shouldComputeCorrectRangeValue) {
    EXPECT_EQ(ulamspiral::computeNumbersRange(3), 10);
    EXPECT_EQ(ulamspiral::computeNumbersRange(5), 26);
    EXPECT_EQ(ulamspiral::computeNumbersRange(3000), 9000001);
}
