#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./linkedList.hpp"



int main() {
	lList<int> L1;
	lList<int> L2;
	lList<int> F;

	L1.insertKey(1);
	L1.insertKey(100);
	L1.insertKey(20);
	L1.insertKey(100);
	L1.print();

	L2.insertKey(1);
	L2.insertKey(100);
	L2.insertKey(20);
	L2.insertKey(100);
	L2.print();

	F = UNION(L1, L2);
	F.print();
}
