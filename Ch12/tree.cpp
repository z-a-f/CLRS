#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./tree.hpp"

int main() {
	Tree<int> T (new binNode<int>(10));
	// Tree<int> T;

	T.addNode(new binNode<int> (11));
	T.addNode(new binNode<int> (9));
	T.addNode(new binNode<int> (8));
	T.addNode(new binNode<int> (12));

	T.printOrdered();

	binNode <int> *find;
	find = T.iterativeTreeSearch(11);
	cout << find->getKey() << endl; // print 11
	
	find = T.treeMaximum();
	cout << find->getKey() << endl; // print 12
	
	find = T.treeSearch(10);
	cout << find->getKey() << endl; // print 10
	find = T.treeSuccessor(find);
	cout << find->getKey() << endl; // print 11
	
	find = T.treeSearch(10);
	cout << find->getKey() << endl; // print 10
	find = T.treePredecessor(find);
	cout << find->getKey() << endl; // print 9

    T.printOrdered();
}
