#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./rbTreeI.hpp"

int main() {
	cout << "This is a string" << endl;
	cout << 42 << endl;

	rbTreeI <int> tree;

	tree.insert(new iNode<int>(16,21));
	tree.insert(new iNode<int>(8,9));
	tree.insert(new iNode<int>(25,30));
	tree.insert(new iNode<int>(5, 8));
	tree.insert(new iNode<int>(15, 23));
	tree.insert(new iNode<int>(17, 19));
	tree.insert(new iNode<int>(26, 26));
	tree.insert(new iNode<int>(0, 3));
	tree.insert(new iNode<int>(6, 10));
	tree.insert(new iNode<int>(19, 20));
	tree.print();
}