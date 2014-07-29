#define _RED_	true
#define _BLACK_	false

template <typename T>
class Node {
private:
	T key;
	bool color;	// 0-> black, 1->red
public:
	Node<T> * left;
	Node<T> * right;
	Node<T> * parent;
	
	Node() {
		this->color = _BLACK_;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	Node(Node <T> * NIL) {
		this->color = _BLACK_;
		this->left = NIL;
		this->right = NIL;
		this->parent = NIL;
	}
	Node(T key) {
		this->color = _BLACK_;
		this->key = key;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	
	~Node() {
		delete this->left;
		delete this->right;
	}
	
	T getKey() {
		return this->key;
	}
	bool getColor() {
		return this->color;
	}
	void setColor(bool color) {
		this->color = color;
	}
};

template <typename T>
class rbTree {
private:
	Node<T> * root;
	Node<T> * NIL; // sentinel
public:
	rbTree() {
		this->root = new Node<T>;
		this->NIL = new Node<T>;
		
		/* Set the NIL to point to itself */
		this->NIL->parent = this->NIL;
		this->NIL->left = this->NIL;
		this->NIL->right = this->NIL;
		
		this->root = this->NIL;
	}
	
	~rbTree() {
		this->root->parent = NULL;
		this->root->left = NULL;
		this->root->right = NULL;
		this->NIL->parent = NULL;
		this->NIL->left = NULL;
		this->NIL->right = NULL;

		delete root;
		delete NIL;
	}
	
	void leftRotate(Node<T> *x) {	// page 313
		Node<T> * y = x->right;	// set y
		x->right = y->left;		// turn y's left subtree into x's right subtree
		if (y->left != this->NIL) {
			y->left->parent = x;
		}
		y->parent = x->parent;	// link x's parent to y
		if (x->parent == this->NIL) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;		// put x on y's left
		x->parent = y;
	}
	
	void rightRotate(Node<T> *x) { // page 313
		Node<T> * y = x->left;
		x->left = y->right;		
		if (y->right != this->NIL) {
			y->right->parent = x;
		}
		y->parent = x->parent;	
		if (x->parent == this->NIL) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;	
		x->parent = y;
	}
	
	void insert (Node<T> * z) {  // page 315
		/*
		if (this->root = this->NIL) {	// The tree is empty
			z->left = this->NIL;
			z->right = this->NIL;
			z->parent = this->NIL;
			z->setColor(_BLACK_);
			this->root = z;
			return;
		}
		*/
		// Assume all keys are distinct!
		Node <T> * y = this->NIL;
		Node <T> * x = this->root;
		while (x != this->NIL) {
			y = x;
			if (z->getKey() < x->getKey()) {
				x = x->left;
			} else {
				x = x->right;
			}
		}
		z->parent = y;
		if (y == this->NIL) {
			this->root = z;
		} else if (z->getKey() < y->getKey()) {
			y->left = z;
		} else {
			y->right = z;
		}
		z->left = this->NIL;
		z->right = this->NIL;
		z->setColor(_RED_);
		insertFixup(z);
	}
	
	void insertFixup(Node <T> * z) {
		Node <T> * y;
		while (z->parent->getColor() == _RED_) {
			if (z->parent == z->parent->parent->left) {
				y = z->parent->parent->right;
				if (y->getColor() == _RED_) {
					z->parent->setColor(_BLACK_);
					y->setColor(_BLACK_);
					z->parent->parent->setColor(_RED_);
					z = z->parent->parent;
				} else {
					if (z == z->parent->right) {
						z = z->parent;
						leftRotate(z);
					}
					z->parent->setColor(_BLACK_);
					z->parent->parent->setColor(_RED_);
					rightRotate(z->parent->parent);
				}
			} else {
				y = z->parent->parent->left;
				if (y->getColor() == _RED_) {
					z->parent->setColor(_BLACK_);
					y->setColor(_BLACK_);
					z->parent->parent->setColor(_RED_);
					z = z->parent->parent;
				} else {
					if (z == z->parent->left) {
						z = z->parent;
						rightRotate(z);
					}
					z->parent->setColor(_BLACK_);
					z->parent->parent->setColor(_RED_);
					leftRotate(z->parent->parent);
				}
			}
		}
		this->root->setColor(_BLACK_);
	}
			
	
	void print() {
		cout << "\nROOT/COLOR: " << this->root->getKey() << '/' << (this->root->getColor() ? "RED" : "BLACK")  << endl;
		cout << "NIL/COLOR: " << this->NIL->getKey() << '/' << (this->NIL->getColor() ? "RED" : "BLACK")  << endl;
		print(this->root);
		cout << endl;
	}	
	void print(Node<T> * node) {
		if (node != this->NIL) {
			print(node->left);
			cout << node->getKey() << '/' << (node->getColor() ? 'R' : 'B') << '\t';
			print(node->right);
		}
	}
	
};













