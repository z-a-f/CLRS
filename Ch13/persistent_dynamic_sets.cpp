#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"


template <typename T>
class pdsNode {
private:
	T key;
public:
	pdsNode<T> * left;
	pdsNode<T> * right;
	
	pdsNode() {
		this->left = NULL;
		this->right = NULL;
	}
	pdsNode(T key) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
	~pdsNode() {
		delete this->left;
		delete this->right;
	}
	
	T getKey() {
		return this->key;
	}
};

template <typename T>
class pdsTree {
private:
	pdsNode <T> * root;
public:
	pdsTree() {
		root = NULL;
	}
	pdsTree(pdsNode<T> * node) {
		root = node;
	}
	~pdsTree() {
		delete root;
	}

	void insert(pdsNode<T> * node) {
		pdsNode <T> * y = NULL;
	    pdsNode <T> * x = this->root;
	    while (x != NULL) {
	        y = x;
	        if (node->getKey() < x->getKey())
	            x = x->left;
	        else
	        	x = x->right;	            
	    }
	    if (y == NULL)
	    	this->root = node;	// tree was empty
	    else if (node->getKey() < y->getKey())
	    	y->left = node;
	    else
	    	y->right = node;
	}

	void print(pdsNode <T> * node) {
		if (node != NULL) {
			print (node->left);
			cout
		}
	}
};

int main() {
	pdsTree<int> tree;
	tree.insert(new pdsNode<int>(10));
}
