#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./queue.hpp"


int main() {
  queue<int> Q(6);
  Q.print();

  Q.enqueue(4); Q.print();
  Q.enqueue(1); Q.print();
  Q.enqueue(3); Q.print();
  Q.dequeue(); Q.print();
  Q.enqueue(8); Q.print();
  Q.dequeue(); Q.print();
}
