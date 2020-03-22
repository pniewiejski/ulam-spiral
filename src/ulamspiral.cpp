#include "ulamspiral.hpp"

const std::shared_ptr<std::vector<bool>> ulamspiral::sieveOfEratosthenes(const int range) {
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

const int ulamspiral::computeNumbersRange(const int width) {
  return (width * width) + 1;
}

const std::shared_ptr<std::vector<bool>> ulamspiral::makeUlamSpiral(const int width) {
  int range = ulamspiral::computeNumbersRange(width);
  auto sievedNumbers = ulamspiral::sieveOfEratosthenes(range);
  auto spiral = std::make_shared<std::vector<bool>>(std::vector<bool>(width * width));

  Point point = {// start from the middle of "square"
                 .x = width % 2 ? width / 2 : (width / 2) - 1,
                 .y = width % 2 ? width / 2 : (width / 2) - 1};

  int directionIndicator = 0;
  int stepsToNextTurn = 1;
  int spiralSideLength = 1;

  auto getDirection = [&directionIndicator]() { return directionIndicator % 4; };
  auto updateDirection = [&point, &getDirection]() {
    switch (getDirection()) {
      case DIRECTION_UP:
        return point.y--;
      case DIRECTION_DOWN:
        return point.y++;
      case DIRECTION_RIGHT:
        return point.x++;
      case DIRECTION_LEFT:
        return point.x--;
    }
    return 0;
  };

  for (int i = 0; i < spiral->size(); ++i) {
#ifdef DEBUG
    std::cout << "Assign to spiral at (" << point.x + 1 << ";" << point.y + 1 << ") a value of "
              << sievedNumbers->at(i) << std::endl;
#endif
    spiral->at(point.y * width + point.x) = sievedNumbers->at(i);

    stepsToNextTurn--;
    int currentDirection = getDirection();
    if (!stepsToNextTurn &&
        (currentDirection == DIRECTION_UP || currentDirection == DIRECTION_DOWN)) {
      // Notice that the length of spiral's side increasing only when turning up or down.
      spiralSideLength++;
    }

    updateDirection();

    if (!stepsToNextTurn) {
      stepsToNextTurn = spiralSideLength;
      directionIndicator++;
    }
  }

#ifdef DEBUG
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

void ulamspiral::saveToFile(std::shared_ptr<std::vector<bool>> spiral, int width,
                            const std::string& fileName) {
  if (width * width != spiral->size()) {
    throw std::invalid_argument("Provided width doesn't match the size of spiral");
  }

  std::ofstream image(fileName);
  image << "P1\n";
  image << width << " " << width << "\n";

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      image << spiral->at(j + i * width) << " ";
    }
    image << "\n";
  }

  image.close();
}