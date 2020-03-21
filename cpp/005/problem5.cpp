#include <iostream>

int main() {
  int max = 20;
  bool finish = false;
  int smallestPositive = 1;

  while (!finish) {
    bool remainder = false; // No remainders from division.

    for (int i = 1; i <= max; ++i) {
      if (smallestPositive % i) { // Remainder after division.
        remainder = true;
        break;
      }
    }

    if (!remainder) { finish = true; } else { ++smallestPositive; }
  }

  std::cout << "Smallest positive for 1 -> " << max << " is " << smallestPositive;
  std::cout << std::endl;
  return(smallestPositive);
}

