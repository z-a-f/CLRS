#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./queue.hpp"


int main() {
  queue<int> S(3);
  
  S.print();
  S.enqueue(10);
  S.print();
  S.enqueue(2);
  S.print();
  S.enqueue(3);
  S.print();
  S.enqueue(4);
  S.print();
  S.enqueue(2);
  S.print();
  cout << S.dequeue() << endl;
  S.print();
}
