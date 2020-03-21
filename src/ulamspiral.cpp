#include "ulamspiral.hpp"

std::shared_ptr<std::vector<bool>> ulamspiral::sieveOfEratosthenes(int range) {
  auto sieve = std::make_shared<std::vector<bool>>(std::vector<bool>(range, true));

  sieve->at(0) = false;  // 1 is not a prime number

  for (int i = 2; i * i <= range; ++i) {
    if (sieve->at(i - 1)) {
      for (int j = 2 * i; j <= range; j += i) {
        sieve->at(j - 1) = false;
      }
    }
  }

#ifdef DEBUG
  for (int i = 0; i < range - 1; i++)
    std::cout << "Number:" << i + 1 << " Is prime:" << sieve->at(i) << std::endl;
#endif

  return sieve;
}

int ulamspiral::computeNumbersRange(int width) { return (width * width) + 1; }

std::shared_ptr<std::vector<bool>> ulamspiral::makeUlamSpiral(int width) {
  int range = ulamspiral::computeNumbersRange(width);
  auto sievedNumbers = ulamspiral::sieveOfEratosthenes(range);
  auto spiral = std::make_shared<std::vector<bool>>(std::vector<bool>(width * width));

  int pointX;
  int pointY;

  if (width % 2) {
    pointX = width / 2;
  } else {
    pointX = (width / 2) - 1;
  }

  pointY = pointX;

  int directionIndicator = 0;
  int stepsToNextTurn = 1;
  int spiralSideLength = 1;

  for (int i = 0; i < spiral->size(); ++i) {
#ifdef DEBUG
    std::cout << "Assign to spiral at (" << pointX + 1 << ";" << pointY + 1 << ") a value of "
              << sievedNumbers->at(i) << std::endl;
#endif
    spiral->at(pointY * width + pointX) = sievedNumbers->at(i);

    stepsToNextTurn--;

    if (!stepsToNextTurn && (directionIndicator % 4 == 1 || directionIndicator % 4 == 3)) {
      // Notice that the length of spiral's side increasing only when turning up or down.
      spiralSideLength++;
    }

    if (directionIndicator % 4 == 1)
      pointY--;  // move up
    else if (directionIndicator % 4 == 2)
      pointX--;  // move left
    else if (directionIndicator % 4 == 3)
      pointY++;  // move down
    else
      pointX++;  // move right

    if (!stepsToNextTurn) {
      stepsToNextTurn = spiralSideLength;
      directionIndicator++;
    }
  }

#ifdef DEBUG
  for (int i = 0; i < range - 1; i++) {
    std::cout << spiral->at(i);
  }
  std::cout << std::endl;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << spiral->at(j + i * width) << " ";
    }
    std::cout << std::endl;
  }
#endif

  return spiral;
}