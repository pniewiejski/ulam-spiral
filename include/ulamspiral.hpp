#pragma once
#include <fstream>
#include <memory>
#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

#define MAX_WIDTH 46340

#define DIRECTION_UP 1
#define DIRECTION_DOWN 3
#define DIRECTION_RIGHT 0
#define DIRECTION_LEFT 2

struct Point {
  int x;  // column
  int y;  // row
};
struct Spiral {
  const std::shared_ptr<std::vector<bool>> spiral;
  const int width;
};

namespace ulamspiral {
const int computeNumbersRange(const int width);
const std::shared_ptr<std::vector<bool>> sieveOfEratosthenes(const int range);
const Spiral makeUlamSpiral(const int width);
void saveToFile(const Spiral& spiral, const std::string& fileName);
}  // namespace ulamspiral