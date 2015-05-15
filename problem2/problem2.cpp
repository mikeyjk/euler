#include <iostream>
// Incorrect solutions will pass, as the first term to exceed
//   4,000,000 is 5,702,887 (not evenly divisible by 2).
// "...whose values do not exceed four million...":
// If it were divisible by 2 this would punish not checking
//   the value prior to adding to the sum.

static int limit = 4000000;

int fibonacci(int previous, int current) {
  int sum = 0;
  std::cout << "Sequence: " << current;
  while (current <= limit) {
    int tmp = current;
    current = previous + current;
    if (current <= limit) {
      if(!(current % 2)) {
        sum += current;
      }
    } else { break; }
    std::cout << ", " << current;
    previous = tmp;
  }
  std::cout << "." << std::endl;
  return(sum);
}

int fibonacciRecursive(int previous, int current, int sum) {
  int next = previous + current;
  std::cout << ", " <<  next;
  if (next <= limit && !(next % 2)) {
    sum = fibonacciRecursive(current, next, sum + next);
  }
  return sum;
}

// Just to format sequence output.
int fibRecWrap(int previous, int current, int sum) {
  std::cout << "Sequence: " << current;
  int ret = fibonacciRecursive(previous, current, sum);
  std::cout << "." << std::endl;
  return(ret);
}

int main() {
  std::cout << "Sum: " << fibonacci(0, 1) << std::endl;
  std::cout << "Sum (recursive): " << fibRecWrap(0, 1, 0) << std::endl;
  return(1);
}

