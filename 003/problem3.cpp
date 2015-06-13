#include <iostream>
#include <vector>

// TODO: template argument so it doesn't need to explicitly be
// a long long int?

// static int limit = 10;

std::vector<long long int> factors(long long int findFactor) {
  std::vector<long long int> factorList;

  for (long long int i = 0; i < findFactor; ++i) {
    if (!findFactor % i) { // Factor (divides evenly).
      factorList.push_back(i);
    }
  }

  return factorList;
}

/**
 * Determine if a number is prime.
 */
bool isPrime(long long int val) {
  bool prime = true;
  if (!(val % 1) && !(val % val)) { // Check 1
    for (int i = 2; i < val; ++i) {
      if (val % i) {
        prime = false;
      }
    }
  } else {
    prime = false;
  }
  return (prime);
}

int main() {
  for (int i = 1; i < 100; ++i) {
    std::cout << i;
    if (isPrime(i)) { std::cout << " is a prime number."; }
    else { std::cout << " is not a prime number."; }
    std::cout << std::endl;
  }
}
