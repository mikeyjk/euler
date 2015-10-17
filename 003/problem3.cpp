#include <iostream>
#include <vector>

/**
 * TODO: list reasoning for long long int (I mean, it is obvious but may
 * as well list the specifics).
 *
 * Trial division reading:
 *  - https://www.khanacademy.org/computing/computer-science/cryptography/comp-number-theory/a/trial-division
 *  - https://en.wikipedia.org/wiki/Trial_division
 *  - http://rosettacode.org/wiki/Primality_by_trial_division
 */

// static int limit = 10;

// TODO: template argument so it doesn't need to explicitly be
// a long long int?
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
 * Determine if a number is prime (return true) or non-prime (return false).
 *
 * "A prime number (or a prime) is a natural number greater than 1 that has
 * no positive divisors other than 1 and itself. A natural number greater than
 * 1 that is not a prime number is called a composite number. For example, 5 is
 * prime because 1 and 5 are its only positive integer factors, whereas 6 is
 * composite because it has the divisors 2 and 3 in addition to 1 and 6."
 *  - https://en.wikipedia.org/wiki/Prime_number
 */
bool isPrime(long long int val) {
  bool prime = true;
  if (val <= 1) {
    prime = false;
  } else { // > 1.
    // If: val % i == 0, then val / i == val || 1.
    // If n is a prime, then the only value of x that should == 0, should be 1 and n.
    // The only numbers that a prime should divide evenly into is 1 and itself.
    if (!(val % 1) && !(val % val)) { // Check basic pre-requisites for a prime.
      for (int i = 2; i < val; ++i) {
        if (i != val) { // Gross - prevent redundant check..
          if (!(val % i)) { // Check not a composite number.
            prime = false;
          }
        }
      }
    } else {
      prime = false;
    }
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

