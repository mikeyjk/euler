#include <iostream>
static int limit = 10;

/**
 * Currently unsure of the best way to test this:
 *
 * "By taking any two primes and concatenating them in any order
 *   the result will always be prime."
 *
 * For now, will use all primes prior to the prime being tested.
 */
bool isPrime(int val) {
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
