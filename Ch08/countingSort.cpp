#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./countingSort.hpp"

int main() {
  int ar[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
  vector<int> A;
  A.insert(A.begin(), ar, ar+15);

  printVector(A);
  countingSort(&A, 10);
  printVector(A);
}
