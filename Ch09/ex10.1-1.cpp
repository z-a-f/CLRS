#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./stack.hpp"


int main() {
  stack<int> S(6);
  S.print();

  S.push(4); S.print();
  S.push(1); S.print();
  S.push(3); S.print();
  S.pop(); S.print();
  S.push(8); S.print();
  S.pop(); S.print();
}
