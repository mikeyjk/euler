#include <iostream>
#include <vector>

// Sum of all proper divisors of n.
int d(int n) {
  int sum = 0;
  std::cout << "Divisors: ";
  for (int i = 1; i < n; ++i) {
    if (!(n % i)) {
      std::cout << i << " ";
      sum += i;
    }
  }
  std::cout << std::endl;
  return sum;
}

int main() {
  std::vector<std::pair<int, int> > sums;

  for (int i = 0; i < 10000; ++i) {
    sums.push_back(std::pair<int, int>(i, d(i)));
  }
}

