#include <iostream>
#include <vector>

// Sum of all proper divisors of n.
int d(int n) {
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    if (!(n % i)) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  int totalSum = 0;

  std::vector<std::pair<int, int> > sums;

  for (int i = 0; i < 10000; ++i) {
    sums.push_back(std::pair<int, int>(i, d(i)));
  }

  for (std::pair<int, int> sumOne : sums) {
    if (sumOne.first != sumOne.second) {
      for (std::pair<int, int> sumTwo : sums) {
        if (sumOne.first == sumTwo.second && sumOne.second == sumTwo.first) {
          std::cout << "found amicable" << std::endl;
          std::cout << sumOne.first << " " << sumOne.second << std::endl;
          std::cout << sumTwo.first << " " << sumTwo.second << std::endl;
          totalSum += sumOne.second;
          std::cout << totalSum << std::endl;
        }
      }
    }
  }
  std::cout << totalSum << std::endl;
}

