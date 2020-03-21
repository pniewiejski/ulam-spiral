#include <iostream>

#include "ulamspiral.hpp"

int main(int argc, char* argv[]) {
  std::cout << "ulamsprial program called with " << argc << " arguments" << std::endl;
  ulamspiral::makeUlamSpiral(5);
}