#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./linkedList.hpp"

int main() {
	Node <int> *p = new Node<int>; // For searching later on
	cout << "TEST" << endl;
	lListSent<int> L;	L.print();
	L.insertKey(1);		L.print();
	L.insertKey(100);	L.print();
	L.insertKey(20);	L.print();
	L.insertKey(100);	L.print();

	p = L.search(100);
	cout << "Removing the value: " << p->get() << endl;	// This will break if p=NULL
	L.print();
	L.deleteNode(p);
	L.print();
}
