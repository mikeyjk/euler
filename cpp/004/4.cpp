#include <iostream>
#include <string>

int main() {
  int largest = 0;
  for (int x = 1000; x > 99; --x) {
    for (int y = x; y > 99; --y) {
      std::string product = std::to_string(x * y); // std >= c++11.
      std::string reverse(product.rbegin(), product.rend());
      // If equal back and forwards (palindrome check).
      if (product.compare(reverse) == 0) {
        if (x * y > largest) {
          largest = x * y;
        }
      }
    }
  }
  std::cout << "Largest 3 digit palindrome: " << largest << ".";
  std::cout << std::endl;
  return 1;
}
