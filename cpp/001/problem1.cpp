#include <iostream>
#include <string>
#include <sstream> // string -> int.

/**
 * Euler Problem 1.
 * (Pushing these problems for swapping between machines).
 *
 * Takes a single command line argument.
 *   - int defining the max + 1 value.
 *
 * Tried determining if there was a pattern between the sequences
 *   binary values (to see if a bitwise operation to traverse the set was possible.
 *
 * Also tried to see if there was some formula to calc the sum without iterating.
 * Solution is currently just the entry level pseudo-code.
 *
 * 'Mathier' solution? :
 *    https://www.wolframalpha.com/input/?i=
 *    0%2C+3%2C+5%2C+6%2C+9%2C+10%2C+12%2C+1
 *    5%2C+18%2C+20%2C+21%2C+24%2C+25%2C+27%
 *    2C+30%2C+33%2C+35%2C+36%2C+39
 */

int problem1(int limit) {
  int sum = 0;
  for(int n = 0; n < limit; ++n) {
    if(!(n % 3) || !(n % 5)) { // If divisible by 3 or 5.
      sum += n;
    }
  }
  return(sum);
}

int problem1_2(int n, int limit, int sum) {
  if (n < limit) {
    if(!(n % 3) || !(n % 5)) {
      sum += n;
    }
    sum = problem1_2(++n, limit, sum);
  }
  return sum;
}

int main(int argc, char** argv) {
  using std::cout;

  int limit = 1000; // Default.
  if (argc >= 2) { // Allow 1 cmd line arg of max n value.
    std::stringstream limitStr(argv[1]);
    if (!(limitStr >> limit)) { // C++ string to int.
      limit = 1000; // Default.
    } // Else successfull conversion.
  }
  cout << "Standard: " << problem1(limit) << std::endl;
  cout << "Recursive: " << problem1_2(0, limit, 0);
  cout << std::endl;
  return(1);
}

