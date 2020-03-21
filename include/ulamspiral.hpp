#pragma once
#include <memory>
#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

namespace ulamspiral {
int computeNumbersRange(int width);
std::shared_ptr<std::vector<bool>> sieveOfEratosthenes(int range);
std::shared_ptr<std::vector<bool>> makeUlamSpiral(int width);
}  // namespace ulamspiral