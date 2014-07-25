#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./sorts.hpp"

int main() {
  // int ar[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
  int ar[11] = {61, 20, 12, 0, 11, 35, 49, 96, 12, 39, 27};
  vector<int> A;
  A.insert(A.begin(), ar, ar + 11);

  printVector(A);
  radixSort(&A, 4);
  printVector(A);
}
