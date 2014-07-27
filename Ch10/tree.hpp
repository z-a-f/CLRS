template <typename T> class binNode {
public:
	T key;
	binNode *left;
	binNode *right;
	binNode *parent;

	// no arg constructor:
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
};

template<typename T> class Tree {
private:
	binNode <T> *root;
public:
	Tree() {
		this->root = NULL;
	}
	~Tree() {
		if (this->root != NULL)
			freeNode(this->root);
		free(this->root);
	}
	void freeNode(binNode<T> *node) {
		cout << "DELETING\n";
		if (node->left != NULL) {
			freeNode(node->left);
			cout << "Going LEFT\n";
		}

		cout << "DELETING\n";
		if (node->right != NULL) {
			cout << "Going RIGHT\n";
			freeNode(node->right);
		}
		cout << "Getting the PARENT\n";
		free(node->parent);
		free(node);
	}

	void insertKey(T key) {
		binNode <T> *node = new binNode<T>(key);
		insertNode(node);
	}

	void insertNode(binNode<T> *x) {
		insertNode(root, x);
	}

	void insertNode(binNode<T> *node, binNode<T> *x) {
		x->parent = node;
		if (node == NULL) {
			cout << "I'm here\n";
			node = new binNode<T>(x->key);
		} else if (x->key <= node->key) {
			insertNode(node->left, x);
		} else {
			insertNode(node->right, x);
		}
	}

	void print (binNode<T> *node) {
		if (node == NULL) return;
		if (node->left != NULL) {
			print(node->left);
		}

		cout << node->key << ' ';

		if (node->right != NULL) {
			print(node->right);
		}
	}

	void print () {
		print(root);
	}

	void printRoot() {
		if (root != NULL) {
			cout << root->key <<endl;
		} else {
			cout << "ROOT is NULL\n";
		}
	}
};


