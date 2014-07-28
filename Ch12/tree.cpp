#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./tree.hpp"

int main() {
	// Tree<int> T (new binNode<int>(10));
	Tree<int> T;

	T.addNode(new binNode<int> (11));
	T.addNode(new binNode<int> (9));
	T.addNode(new binNode<int> (8));
	T.addNode(new binNode<int> (12));

	T.printOrdered();

	binNode <int> *find;
	find = T.iterativeTreeSearch(11);
	T.printOrdered();

	find = new binNode<int> (30);
	T.printOrdered();

	find = T.treeMaximum();
	cout << find->getKey() <<endl;

	free (find);
}