#include <iostream>
#include <string>
#include <sstream>
static int nLimit = 1000;

// Euler Problem 1.
// Pushing for swapping between machines.
// 'Mathier' solution? :
// https://www.wolframalpha.com/input/?i=
// 0%2C+3%2C+5%2C+6%2C+9%2C+10%2C+12%2C+1
// 5%2C+18%2C+20%2C+21%2C+24%2C+25%2C+27%
// 2C+30%2C+33%2C+35%2C+36%2C+39

int problem1() {
  int sum = 0;

  for(int i = 0; i < nLimit; ++i) {
    if(!(i % 3) || !(i % 5)) {
      sum += i;
    }
  }

  return(sum);
}

int main(int argc, char** argv) {
  // Allow 1 cmd line arg of max n value.
  if (argc >= 2) {
    std::stringstream limitStr(argv[1]);
    if (!(limitStr >> nLimit)) {
      nLimit = 1000; // Default.
    }
  }
  std::cout << problem1() << std::endl;
}
