#include <iostream>
#include <iomanip>
#include <stdlib.h> // exit(), for debug.
#include <cmath> // pow().

// 1000 digits is huge, I will need https://gmplib.org/.
// Hmm, perhaps I have overlooked this. It doesn't seem in the spirit
// of these problems just to throw computation at something.
// I'm confident this library would yield the correct result but I don't
// want to miss the point.

// Tried to determine if there is a pattern between how many fibonacci
// numbers contain the same amount of digit (probably a math crime without
// understanding the full implications of fibonacci correctly).

// row 1: n of fibonacci values that have the corresponding amount of digits.
// row 2: n digits.
// 5, 4, 4, 3, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 4, 5, 5, 4, 4, 4, 4
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24
// Was so excited I found a pattern at dig(12), ecstatic that I found a
// recurring pattern at dig(17). horrified at dig(18).
//
// I'm sure there will be a way to arrive at the answer quick than iterating
// through integers containing <= 1000 digits.

using std::cout;
using std::endl;

/**
 * Sequence is 10 ^ n - 1, where n is the number of digits.
 * Doesn't hold true for 10 ^ 1 which is 0.
 * So for digits 2 -> only does this work.
 */
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
  if (digitAmount(current) < 40) {
    ++n;
    fibonacci(n, current, next);
  }
  return(next);
}

int main() {
  cout << fibonacci(1, 0.0, 1.0) << endl;
  cout << endl;
  return(1);
}

