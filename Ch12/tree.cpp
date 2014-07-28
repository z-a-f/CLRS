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
    
    cout << "After creating the tree and adding base nodes:\n";
	T.printOrdered();

    cout << "After finding key=11:\n";
	binNode <int> *find;
	find = T.iterativeTreeSearch(11);
	if (find != NULL)
	    cout << find->getKey() << endl; // print 11
	else
	    cout << "NULL\n";
	
	cout << "After finding maximum:\n";
	find = T.treeMaximum();
	if (find != NULL)
	    cout << find->getKey() << endl; // print 12
	else
	    cout << "NULL\n";
	
	find = T.treeSearch(10);
	cout << find->getKey() << endl; // print 10
	find = T.treeSuccessor(find);
	cout << find->getKey() << endl; // print 11
	
	find = T.treeSearch(10);
	cout << find->getKey() << endl; // print 10
	find = T.treePredecessor(find);
	cout << find->getKey() << endl; // print 9

    T.printOrdered();
    
    // Check the  treeInsert:
    T.treeInsert(new binNode <int>(3));
    T.printOrdered();
    T.treeInsert(new binNode <int>(5));
    T.printOrdered();
}
