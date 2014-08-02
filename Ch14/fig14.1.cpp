#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./rbTree.hpp"

int main() {
	rbTree<int> tree;

	int ar[20] = {26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 21, 28, 38, 7, 12, 14, 20, 35, 39, 3};
	for (int i = 0; i < 20; i++)
		tree.insert(new Node<int>(ar[i]));
	tree.print();
	
}
