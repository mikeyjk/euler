#include <iostream>
#include <iomanip>
#include <stdlib.h> // exit(), for debug.
#include <cmath> // pow().

// 100 digits is huge, I will need https://gmplib.org/.

// Sequence is 10 ^ n - 1, where n is the number of digits.
// Doesn't hold true for 10 ^ 1 which is 0.
// So for digits 2 -> only does this work.

using std::cout;
using std::endl;

int digitAmount(double val) {
  int amount = 0;
  int limit = 10001;

  if (val / 1 >= 1) { // 1 digit.
    ++amount;

    for (int i = amount; i < limit; ++i)  {
      if (val / pow(10.0, i) >= 1.0) { // 10^1, 10^2, 10^3, ... .
        cout << "val: " << val << " has " << i + 1 << " digits." << endl;
        ++amount;
      } else {
        break; // No sense in checking any higher digits.
      }
    }
  }
  return (amount);
}

// n: position in sequence.
// previous: n-1
// current: n
double fibonacci(int n, double previous, double current) {
  cout << std::setprecision(10001) << "n: " << n << " val: " << current << std::endl;

  double next = previous + current;
  if (digitAmount(current) < 10001) {
    ++n;
    fibonacci(n, current, next);
  }
  return(next);
}

int main() {
  cout << "First 8 digit in fibonnaci sequence: " << fibonacci(1, 0.0, 1.0) << endl;
  cout << endl;
  return(1);
}

