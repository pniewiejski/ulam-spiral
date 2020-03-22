#pragma once
#include <memory>
#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

#define DIRECTION_UP 1
#define DIRECTION_DOWN 3
#define DIRECTION_RIGHT 0
#define DIRECTION_LEFT 2

namespace ulamspiral {
int computeNumbersRange(int width);
std::shared_ptr<std::vector<bool>> sieveOfEratosthenes(int range);
std::shared_ptr<std::vector<bool>> makeUlamSpiral(int width);

struct Point {
  int x;  // column
  int y;  // row
};
}  // namespace ulamspiral