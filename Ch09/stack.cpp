#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./stack.hpp"


int main() {
  stack<int> S(3);
  
  cout << S.pop() << endl;
  S.push(1);
  cout << S.pop() << endl;
  cout << S.pop() << endl;
  
  S.push(1);
  S.push(2);
  S.push(3);
  S.push(4);
  cout << S.pop() << endl;
}
