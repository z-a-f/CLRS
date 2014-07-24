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

void swap (interval *A, interval *B) {
  interval temp = *A;
  *A = *B;
  *B = temp;
}

int partition(vector<interval> *A, int p, int r) {
  interval x = A->at(r);
  int i = p - 1;
  for (int j = p; j <= r-1; j++) {
    if (intervalLT(A->at(j), x) || intervalEQ(A->at(j), x)) {
      i++;
      swap(A->at(i), A->at(j));
    }
  }
  swap(A->at(i+1), A->at(r));
  return i+1;
}

void quickSort(vector<interval> *A, int p, int r) {
  int q;
  if (p < r) {
    q = partition (A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int main() {
  interval ar[5] = {{1, 3}, {0, 2}, {10, 20}, {21,22}, {5,7}};
  vector<interval> A;
  A.insert(A.begin(), ar, ar+5);

  intervalPrint(A);
  quickSort(&A, 0, A.size()-1);
  intervalPrint(A);
}
