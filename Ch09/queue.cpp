#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./queue.hpp"


int main() {
  queue<int> S(3);
  
  S.enqueue(10);
  S.enqueue(2);
  S.enqueue(3);
  S.enqueue(4);
  cout << S.dequeue() << endl;
}
