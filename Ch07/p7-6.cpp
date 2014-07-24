#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./quickSort.hpp"

struct interval {
  int min;
  int max;
};

void intervalPrint(interval in) {
  cout << "{" << in.min << ", " << in.max << "}";
}

void intervalPrint(vector<interval> A) {
  cout << "{ ";
  for (vector<interval>::iterator it = A.begin(); it != A.end(); ++it) {
    intervalPrint(*it);
    cout << " ";
  }
  cout << "}" << endl;
}

bool intervalLT (interval A, interval B) {
  // equivalent to A < B
  // Example:
  //	{1,3} is less then {2, 3}
  return (A.min < B.min);
}

bool intervalGT (interval A, interval B) {
  // equivalent to A > B
  // Example
  //	{3, 4} is greater than {-1, 4}
  return (A.min > B.min);
}

bool intervalEQ (interval A, interval B) {
  // equivalent to A == B
  return ((A.min == B.min) && (A.max == B.max));
}

int main() {
  interval ar[5] = {{1,2}, {0, 1}, {10, 20}, {21,22}, {5,7}};
  vector<interval> A;
  A.insert(A.begin(), ar, ar+5);

  intervalPrint(A);
}
