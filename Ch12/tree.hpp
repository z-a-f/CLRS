template <typename T> 
class binNode {
private:
	T key;
public:
	binNode * left;
	binNode * right;
	binNode * parent;
	binNode() {
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	// arg constructor:
	binNode (T key) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
    
	~binNode() {
		if (left != NULL) delete left;
		if (right != NULL) delete right;
	}
    
	T getKey() {
		return this->key;
	}
	void setKey(T key) {
		this->key = key;
	}
	
};

template<typename T> class Tree {
private:
	binNode <T> *root;

public:
	Tree() {
		this->root = NULL;
	}
	Tree(binNode <T> * node) {
		node->parent = NULL;
		this->root = node;
	}

	~Tree() {
	    if (root != NULL) delete root;
	}
	
	/* BEGIN: inserting a new node */
	// My way:
	void addNode(binNode<T> *&x, binNode<T> * node) { // what's up with the *&???
		if (x == NULL) {
			x = node;
			return;
		} else if (x->getKey() == node->getKey()) {
			node->left = x;
			node->parent = x->parent;
			x->parent = node;
			return;
		}

		if (node->getKey() < x->getKey()) {
			addNode(x->left, node);
		} else {
			addNode(x->right, node);
		}

	}

	void addNode(binNode<T> * node) {
		addNode(this->root, node);
	}
	
	// Book way:
	void treeInsert (binNode <T> *z) { // page 294
	    binNode <T> * y = NULL;
	    binNode <T> * x = this->root;
	    while (x != NULL) {
	        y = x;
	        if (z->getKey() < x->getKey())
	            x = x->left;
	        else
	        	x = x->right;	            
	    }
	    z->parent = y;
	    if (y == NULL)
	    	this->root = z;	// tree was empty
	    else if (z->getKey() < y->getKey())
	    	y->left = z;
	    else
	    	y->right = z;
	}
	/* END: inserting a new node */
	
	binNode<T> * treeSearch(binNode<T> * x, T key) {
		if (x == NULL || key == x->getKey()) {
			return x;
		}
		if (key < x->getKey()) {
			return treeSearch(x->left, key);
		} else {
			return treeSearch(x->right, key);
		}
	}

	binNode<T> * treeSearch(T key) {
		return treeSearch(root, key);
	}

	binNode<T> * iterativeTreeSearch(binNode <T> * x, T key) {
		while (x != NULL && key != x->getKey()){
			if (key < x->getKey())
				x = x->left;
			else 
				x = x->right;
		}
		return x;
	}

	binNode<T> * iterativeTreeSearch(T key) {
		return iterativeTreeSearch(this->root, key);
	}

	binNode<T> *treeMinimum(binNode<T> *node) {
    	/*
    	while (node->left != NULL) {
			node = node->left;
		}
		return node;
		*/
		if (node->left != NULL)
		    return treeMinimum(node->left);
		else
		    return node;
	}

	binNode<T> *treeMinimum() {
	    
		if (root != NULL) {
			return treeMinimum(root);
		}
		return root;
    }

	binNode<T> *treeMaximum(binNode<T> *node) {
	    /*
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
		*/
		if (node->right != NULL)
		    return treeMaximum(node->right);
		else
		    return node;
	}

	binNode<T> *treeMaximum() {
		if (root != NULL) {
			return treeMaximum(root);
		}
		return root;
	}
	
	binNode<T> * treeSuccessor(binNode<T> *x) {
	    if (x == NULL) return x;
	    if (x->right != NULL) return treeMinimum(x->right);
	    binNode <T> *y = x->parent;
	    while (y != NULL && x == y->right) {
	        x = y;
	        y = y->parent;
	    }
	    return y;
	}
	
	binNode<T> * treePredecessor(binNode<T> *x) {
	    if (x == NULL) return x;
	    if (x->left != NULL) return treeMaximum(x->left);
	    binNode <T> *y = x->parent;
	    while (y != NULL && x == y->left) {
	        x = y;
	        y = y->parent;
	    }
	    return y;
	}

	void printOrdered() {
		inorderTreeWalk(root);
		cout << endl;
	}

	void inorderTreeWalk(binNode<T> * node) {
		if (node != NULL) {
			inorderTreeWalk(node->left);
			cout << node->getKey() << '\t';
			inorderTreeWalk(node->right);
		}
	}

};


