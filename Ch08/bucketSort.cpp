#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./sorts.hpp"

int main() {
  float ar[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
  vector<float> A;
  A.insert(A.begin(), ar, ar + 6);
  int n = A.size();

  printVector(A);
  bucketSort(&A, n);
  printVector(A);
}
