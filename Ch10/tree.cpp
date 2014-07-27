#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./tree.hpp"

int main() {
	Tree<int> T;
	cout << "TEST" << endl;
	T.print ();

	// T.insertKey(1);
	binNode <int> *node = new binNode<int>(1);
	T.insertNode(node);
	T.print();
	T.printRoot();
	T.insertKey(2);
	T.insertKey(3);
	T.insertKey(4);
	T.insertKey(5);


}