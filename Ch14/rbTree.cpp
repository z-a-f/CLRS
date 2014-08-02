#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./rbTree.hpp"

int main() {
	rbTree<int> tree;

	tree.insert(new Node <int> (10));
	tree.print();

	tree.insert(new Node <int> (20));
	tree.print();

	tree.insert(new Node <int> (30));
	tree.print();

	tree.insert(new Node <int> (40));
	tree.print();

	tree.insert(new Node <int> (50));
	tree.print();

	tree.insert(new Node <int> (60));
	tree.print();

	tree.insert(new Node <int> (70));
	tree.print();

	tree.insert(new Node <int> (80));
	tree.print();

	tree.insert(new Node <int> (90));
	tree.print();

	tree.insert(new Node <int> (100));
	tree.print();

	Node<int> *node;
	node = tree.osSelect(3);
	cout << endl << node->getKey() << '/' << (node->getColor() ? 'R' : 'B') << '/' << node->getSize() << endl;
	cout << tree.osRank(node) << endl;

	// Check deletion:
	tree.deleteNode(node);
	tree.print();
	delete node;
	

	/*
	tree.insert(new Node <int> (pow(3, 2)));
	tree.printTree();
	
	tree.insert(new Node <int> (19));
	tree.printTree();
	
	tree.insert(new Node <int> (10));
	tree.printTree();
	
	tree.insert(new Node <int> (1));
	tree.printTree();
	
	tree.insert(new Node <int> (15));
	tree.printTree();
	*/
	/*
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
	*/
	// tree.deleteNode(node);
	// tree.print();

	// delete node;
	
}
