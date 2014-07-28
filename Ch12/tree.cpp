#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./tree.hpp"

int main() {
	// Tree<int> T (new binNode<int>(10));
	Tree<int> T;
	
	T.treeInsert(new binNode<int> (10));
	T.treeInsert(new binNode<int> (11));
	T.treeInsert(new binNode<int> (9));
	T.treeInsert(new binNode<int> (8));
	T.treeInsert(new binNode<int> (12));
    
    cout << "The root is: " << T.getRoot()->getKey() << endl;
    
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
	
	cout << "After finding key=10 and its successor:\n";
	find = T.treeSearch(10);
	if (find != NULL)
	    cout << find->getKey() << endl; // print 10
	else
		cout << "NULL\n";
	find = T.treeSuccessor(find);
	if (find != NULL)
	    cout << find->getKey() << endl; // print 11
	else
		cout << "NULL\n";
	
	
	cout << "After finding key=10 and its predecessor:\n";
	find = T.treeSearch(10);
	if (find != NULL)
	    cout << find->getKey() << endl; // print 10
	else
		cout << "NULL\n";
	find = T.treePredecessor(find);
	if (find != NULL)
	    cout << find->getKey() << endl; // print 9
	else
		cout << "NULL\n";

	cout << "Check if the tree was modofied:\n";
    T.printOrdered();
    
    // Check the  treeInsert:
    T.treeInsert(new binNode <int>(3));
    T.printOrdered();
    T.treeInsert(new binNode <int>(5));
    T.printOrdered();
    
	// delete find;
	cout << "After deleting key=10:\n";
	find = T.treeSearch(10);
	T.treeDelete(find);
	T.printOrdered();
	
    cout << "The root is: " << T.getRoot()->getKey() << endl;
}




