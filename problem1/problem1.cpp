#include <iostream>
#include <string>
#include <sstream>

// Euler Problem 1.
// Pushing for swapping between machines.
// 'Mathier' solution? :
// https://www.wolframalpha.com/input/?i=
// 0%2C+3%2C+5%2C+6%2C+9%2C+10%2C+12%2C+1
// 5%2C+18%2C+20%2C+21%2C+24%2C+25%2C+27%
// 2C+30%2C+33%2C+35%2C+36%2C+39

// nLimit(10) = sum(23)
// nLimit(20) = sum(78)
// nLimit(100) = sum(2318)
int problem1(int limit) {
  int sum = 0;
  for(int i = 0; i < limit; ++i) {
    if(!(i % 3) || !(i % 5)) { // If divisible by 3 or 5.
      sum += i;
    }
  }
  return(sum);
}

int main(int argc, char** argv) {
  int limit = 1000; // Default.

  if (argc >= 2) { // Allow 1 cmd line arg of max n value.
    std::stringstream limitStr(argv[1]);
    if (!(limitStr >> limit)) { // C++ string to int.
      limit = 1000; // Default.
    } // Else successfull conversion.
  }
  std::cout << problem1(limit) << std::endl;
  return(1);
}
