template <typename T> 
class binNode {
private:
	T key;
public:
	int height;
	binNode * left;
	binNode * right;
	binNode * parent;
	binNode() {
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->height = 1;
	}
	// arg constructor:
	binNode (T key) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->height = 1;
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
		this->root->height = 1;
	}

	~Tree() {
	    if (root != NULL) delete root;
	}
	
	binNode<T> * getRoot() {
		return this->root;
	}
	
	int getHeight(binNode<T> * node) {
		if (node == NULL) return 0;
		else return node->height;
	}

	// Get Balance factor of node N
	int getBalance(binNode <T> * node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	binNode<T> *rightRotate(binNode<T> *y) {
		binNode<T> *x = y->left;
		binNode<T> *T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Update heights
		y->height = max(getHeight(y->left), getHeight(y->right))+1;
		x->height = max(getHeight(x->left), getHeight(x->right))+1;

		// Return new root
		return x;
	}

	binNode<T> *leftRotate(binNode<T> *x){
		binNode<T> *y = x->right;
		binNode<T> *T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		//  Update heights
		x->height = max(getHeight(x->left), getHeight(x->right))+1;
		y->height = max(getHeight(y->left), getHeight(y->right))+1;

		// Return new root
		return y;
	}

	/* BEGIN: inserting a new node */
	void treeInsert (binNode <T> * z) {
		this->root = treeInsert (this->root, z);
	}

	binNode <T> * treeInsert (binNode <T> * node, binNode<T> *z) { // custom (BST)
		// Step 1.
		if (node == NULL) {
			 return z; // Empty root
		}
		if (z->getKey() < node->getKey()) {
			node->left = treeInsert(node->left, z);
		} else {
			node->right = treeInsert(node->right, z);
		}

		// Step 2.
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

		// Step 3.
		int balance = getBalance(node);

		// Step 4.
		// If this node becomes unbalanced, then there are 4 cases
		// Left Left Case
		if (balance > 1 && z->getKey() < node->left->getKey())
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && z->getKey() > node->right->getKey())
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && z->getKey() > node->left->getKey()) {
			node->left =  leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && z->getKey() < node->right->getKey()) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		/* return the (unchanged) node pointer */
		return node;
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
		if (node == NULL)
			return node;

		if (node->left != NULL)
		    return treeMinimum(node->left);
		else
		    return node;
	}

	binNode<T> *treeMinimum() {
		return treeMinimum(root);
    }

	binNode<T> *treeMaximum(binNode<T> *node) {
	    /*
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
		*/
		if (node == NULL)
			return node;
			
		if (node->right != NULL)
		    return treeMaximum(node->right);
		else
		    return node;
	}

	binNode<T> *treeMaximum() {
		return treeMaximum(root);
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
	
	void transplant(binNode<T> * u, binNode<T> * v){ // page 296
		if (u->parent == NULL) {	// This is the root
			this->root = v;
		} else if (u == u->parent->left) { // left branch
			u->parent->left = v;
		} else {	// right brach
			u->parent->right = v;
		}
		if (v != NULL) {
			v->parent = u->parent;
		}
	}
	
	void treeDelete(binNode<T> * z) { // page 298
		binNode<T> * y;
		if (z == NULL) { // node z doesn't exist
			cout << "Cannot delete node!\n";
			return;	
		}
		if (z->left == NULL) {
			transplant(z, z->right);
		} else if (z->right == NULL) {
			transplant(z, z->left);
		} else {
			y = treeMinimum(z->right);
			// cout << y->getKey() << endl;
			if (y->parent != z) {
				transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			transplant (z, y);
			y->left = z->left;
			y->left->parent = y;
			// Do we need to make sure z is not pointing back?
		}
		// Free - get rid of the pointers?
		z->parent = NULL;
		z->left = NULL;
		z->right = NULL;
		delete z;
		balance(this->root);
	}
	
	void balance(binNode<T> * node) {
		// Step 1. Update the heights (I know - inefficient)
		heightsUpdate(node);

		// Step 2. 
	}

	int heightsUpdate() {
		return heightsUpdate(this->root);
	}

	int heightsUpdate(binNode<T> *& node) {
		int hl, hr;
		if (node != NULL) {
			hl = heightsUpdate(node->left) + 1;
			hr = heightsUpdate(node->right) + 1;
			node->height = max(hl, hr);
			return node->height;
		} else {
			return 0;
		}

	}

	void printOrdered() {
		inorderTreeWalk(root);
		cout << endl;
	}

	void inorderTreeWalk(binNode<T> * node) {
		if (node != NULL) {
			inorderTreeWalk(node->left);
			cout << node->getKey() << '/' << node->height << '\t';
			inorderTreeWalk(node->right);
		}
	}

};


