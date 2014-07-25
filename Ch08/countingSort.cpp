#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./sorts.hpp"

int main() {
  // int ar[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
  int ar[11] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
  vector<int> A;
  A.insert(A.begin(), ar, ar+11);

  printVector(A);
  countingSort(&A, 10);
  printVector(A);
}
