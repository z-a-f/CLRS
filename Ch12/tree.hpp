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
		free(left);
		free(right);
		free(parent);
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
		free(root); // binNodes are freed
	}
	
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


