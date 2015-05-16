#include <iostream>
// Incorrect solutions will pass, as the first term to exceed
//   4,000,000 is 5,702,887 (not evenly divisible by 2).
// "...whose values do not exceed four million...":
// If it were divisible by 2 this would punish not checking
//   the value prior to adding to the sum.

using std::cout;
using std::endl;
static int limit = 4000000;

int fibonacci(int previous, int current) {
  int sum = 0;
  cout << "Sequence: " << current;
  while (current <= limit) {
    int tmp = current;
    current = previous + current;
    if (current <= limit) {
      if(!(current % 2)) {
        sum += current;
      }
    } else { break; }
    cout << ", " << current;
    previous = tmp;
  }
  cout << "." << endl << endl;
  return(sum);
}

int fibonacciRecursive(int previous, int current, int sum) {
  int next = previous + current;
  if (next <= limit) {
    cout << ", " <<  next;
    if (!(next % 2)) { sum += next; }
    sum = fibonacciRecursive(current, next, sum);
  }
  return sum;
}

// Just to format sequence output.
int fibRecWrap(int previous, int current, int sum) {
  int ret = 0;
  cout << "Sequence: " << current;
  ret = fibonacciRecursive(previous, current, sum);
  cout << "." << endl << endl;
  return(ret);
}

int main() {
  cout << "Sum: " << fibonacci(0, 1) << endl;
  cout << endl;
  cout << "Sum (recursive): " << fibRecWrap(0, 1, 0);
  cout << endl;
  return(1);
}

