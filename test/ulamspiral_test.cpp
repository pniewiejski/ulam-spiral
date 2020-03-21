#include "ulamspiral.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(ulamspiral, shouldComputeCorrectRangeValue) {
  EXPECT_EQ(ulamspiral::computeNumbersRange(3), 10);
  EXPECT_EQ(ulamspiral::computeNumbersRange(5), 26);
  EXPECT_EQ(ulamspiral::computeNumbersRange(3000), 9000001);
}

TEST(ulamspiral, shouldMarkAllPrimes) {
  auto sievedPrimes = ulamspiral::sieveOfEratosthenes(4);
  EXPECT_THAT(*sievedPrimes, testing::ElementsAre(0, 1, 1, 0));

  sievedPrimes = ulamspiral::sieveOfEratosthenes(16);
  EXPECT_THAT(*sievedPrimes, testing::ElementsAre(0, 1, 1, 0, 1,    // 1, 2, 3, 4, 5
                                                  0, 1, 0, 0, 0,    // 6, 7, 8, 9, 10
                                                  1, 0, 1, 0, 0, 0  // 11, 12, 13, 14, 15, 16
                                                  ));
}

TEST(ulamspiral, shouldGenerateUlamSpiral) {
  auto spiral = ulamspiral::makeUlamSpiral(5);
  EXPECT_THAT(*spiral, testing::ElementsAre(1, 0, 0, 0, 1,  // 17, 16, 15, 14, 13
                                            0, 1, 0, 1, 0,  // 18,  5,  4,  3, 12
                                            1, 0, 0, 1, 1,  // 19,  6,  1,  2, 11
                                            0, 1, 0, 0, 0,  // 20,  7,  8,  9, 10
                                            0, 0, 1, 0, 0   // 21, 22, 23, 24, 25
                                            ));
}