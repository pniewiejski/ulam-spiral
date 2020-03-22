#include <iostream>
#include <string>

#include "ulamspiral.hpp"

int main(int argc, char* argv[]) {
  std::cout << "ulamsprial program called with " << argc << " arguments" << std::endl;
  int width = 100;
  if (argc > 1) {
    try {
      int parsed = std::stoi(argv[1]);
      width = parsed < MAX_WIDTH ? parsed : width;
    } catch (const std::exception& e) {
      std::cerr << e.what() << "\n";
      std::cerr << "Error: " << argv[1] << " is not an integer" << std::endl;

      return 1;
    }
  }
  std::cout << "Spiral width will be " << width << std::endl;

  auto spiral = ulamspiral::makeUlamSpiral(width);
  ulamspiral::saveToFile(spiral, "output.pbm");
}