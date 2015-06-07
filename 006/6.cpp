#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

int main() {
  std::cout << std::setprecision(std::numeric_limits<double>::digits10);

  for (int natural = 1; natural < 102; ++natural) {
    double sum = 0; // sum of i.
    double square = 0; // sum of square of i.

    for (double i = 1; i < natural; ++i) {
      sum += i;
      square += pow(i, 2);
      if (natural == 1) {
        std::cout << i << "!: " << sum << ", " << square << std::endl;
      }
    }

    sum = pow(sum, 2); // squared sum of i.
    std::cout << natural << ": " << sum << " - " << square << " = ";
    std::cout << sum - square;
    std::cout << std::endl;
  }
  return 1;
}
