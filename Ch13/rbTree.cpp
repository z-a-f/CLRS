#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./rbTree.hpp"

int main() {
	rbTree<int> tree;

	tree.insert(new Node <int> (pow(3, 2)));
	tree.print();
	
	tree.insert(new Node <int> (19));
	tree.print();
	
	tree.insert(new Node <int> (10));
	tree.print();
	
	tree.insert(new Node <int> (1));
	tree.print();
	
	tree.insert(new Node <int> (15));
	tree.print();
	
	tree.insert(new Node <int> (23));
	tree.print();
	
	tree.insert(new Node <int> (29));
	tree.print();

	tree.insert(new Node <int> (27));
	tree.print();

	tree.insert(new Node <int> (25));
	tree.print();

	tree.insert(new Node <int> (30));
	tree.print();

	tree.insert(new Node <int> (28));
	tree.print();

	Node<int> *node = tree.search(19);
	cout << node->getKey() <<endl;
	tree.print();

	tree.deleteNode(node);
	tree.print();

	delete node;
}
