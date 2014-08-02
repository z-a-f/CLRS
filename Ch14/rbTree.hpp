#ifndef RBTREE_H_
#define RBTREE_H_


#define _RED_	true
#define _BLACK_	false

template <typename T>
class Node {
private:
	T key;
	bool color;	// 0-> black, 1->red
	unsigned int size;	// Size of the current node
public:
	Node<T> * left;
	Node<T> * right;
	Node<T> * parent;
	
	Node() {
		this->color = _BLACK_;
		this->key = 0;
		this->size = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	Node(Node <T> * NIL) {
		this->color = _BLACK_;
		this->key = 0;
		this->size = 0;
		this->left = NIL;
		this->right = NIL;
		this->parent = NIL;
	}
	Node(T key) {
		this->color = _BLACK_;
		this->key = key;
		this->size = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	
	~Node() {
		/*
		delete left;
		delete right;		
		*/
	}
	
	T getKey() {
		return this->key;
	}
	void setKey(T key) {
		this->key = key;
	}
	bool getColor() {
		return this->color;
	}
	void setColor(bool color) {
		this->color = color;
	}
	unsigned int getSize() {
		return this->size;
	}
	void setSize(unsigned int size) {
		this->size = size;
	}

};

template <typename T>
class rbTree {
protected:
	Node<T> * root;
	Node<T> * NIL; // sentinel
	void treeDelete(Node <T> * node) {
		// Use postorder tree walk to delete the entries
		if (node != NULL && node != NIL) {
			treeDelete(node->left);
			treeDelete(node->right);
			delete node;
		}
	}
public:
	rbTree() {
		// this->root = new Node<T>;
		this->NIL = new Node<T>;
		
		/* Set the NIL to point to itself */
		this->NIL->parent = this->NIL;
		this->NIL->left = this->NIL;
		this->NIL->right = this->NIL;
		this->NIL->setSize(0);
		this->NIL->setColor(_BLACK_);

		this->root = this->NIL;
	}
	rbTree(Node<T> * node) {
		this->root = node;
		this->root->parent = this->NIL;
		fixTree(this->root);
	}
	
	~rbTree() {
		// delete this->root->parent;
		treeDelete(this->root);
		delete this->NIL;
	}

	void fixTree(Node<T> * node) {
		// replace NULL's with NIL's
		if (node->left == this->NIL) {
			return;
		} else if (node->left == NULL) {
			node->left = this->NIL;
			return;
		} else {
			fixTree(node->left);
		}
		if (node->right == this->NIL) {
			return;
		} else if (node->right == NULL) {
			node->right = this->NIL;
			return;
		} else {
			fixTree(node->right);
		}
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
		// Change sizing:
		y->setSize(x->getSize());
		x->setSize(x->left->getSize() + x->right->getSize() + 1);
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
		// Change sizing:
		y->setSize(x->getSize());
		x->setSize(x->left->getSize() + x->right->getSize() + 1);
	}
	
	void insert (Node<T> * z) {  // page 315
		// Assume all keys are distinct!
		z->setSize(1);
		Node <T> * y = this->NIL;
		Node <T> * x = this->root;
		while (x != this->NIL) {
			x->setSize(x->getSize()+1);
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
	
	void insertFixup(Node <T> * z) {	// page 316
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
	
	void transplant(Node<T> * u, Node<T> * v) {	// page 323
		if (u->parent == this->NIL) {
			this->root = v;
		} else if (u == u->parent->left) {
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNode (Node<T> * z) { // page 324
		Node <T> * y = z;
		Node <T> * x;
		bool yOriginalColor = y->getColor();
		if (z->left == this->NIL) {
			x = z->right;
			transplant(z, z->right);
		} else if (z->right == this->NIL) {
			x = z->left;
			transplant(z, z->left);
		} else {
			y = treeMinimum(z->right);
			yOriginalColor = y->getColor();
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			} else {
				transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->setColor(z->getColor());
		}
		// Fix the size by traversing from node y to the top, while decrementing the parents
		/*while (y->parent != this->NIL) {
			y->parent->setSize(y->parent->getSize()-1);
			y = y->parent;
		}*/
		while (y->parent != this->NIL) {
			y->setSize(y->getSize()-1);
			y = y->parent;
		}
		this->root->setSize(this->root->getSize() - 1);

		// Fix the node colors:
		if (yOriginalColor == _BLACK_) {
			deleteFixup(x);
		}
	}

	void deleteFixup(Node <T> * x) {	// page 326
		Node <T> * w;
		while (x != this->root && x->getColor() == _BLACK_) {
			if (x == x->parent->left) {
				w = x->parent->right;
				if (w->getColor() == _RED_) {
					w->setColor(_BLACK_);
					x->parent->setColor(_RED_);
					leftRotate(x->parent);
					w = x->parent->right;
				}
				if (w->left->getColor() == _BLACK_ && w->right->getColor() == _BLACK_) {
					w->setColor(_RED_);
					x = x->parent;
				} else {
					if (w->right->getColor() == _BLACK_) {
						w->left->setColor(_BLACK_);
						w->setColor(_RED_);
						rightRotate(w);
						w = x->parent->right;
					}
					w->setColor(x->parent->getColor());
					x->parent->setColor(_BLACK_);
					w->right->setColor(_BLACK_);
					leftRotate(x->parent);
					x = this->root;
				}
			} else {
				w = x->parent->left;
				if (w->getColor() == _RED_) {
					w->setColor(_BLACK_);
					x->parent->setColor(_RED_);
					rightRotate(x->parent);
					w = x->parent->left;
				}
				if (w->right->getColor() == _BLACK_ && w->left->getColor() == _BLACK_) {
					w->setColor(_RED_);
					x = x->parent;
				} else {
					if (w->left->getColor() == _BLACK_) {
						w->right->setColor(_BLACK_);
						w->setColor(_RED_);
						leftRotate(w);
						w = x->parent->left;
					}
					w->setColor(x->parent->getColor());
					x->parent->setColor(_BLACK_);
					w->left->setColor(_BLACK_);
					rightRotate(x->parent);
					x = this->root;
				}
			}
		}
		x->setColor(_BLACK_);
	}

	Node <T> * treeMinimum(Node <T> * node) {
		if (node->left != this->NIL)
			return treeMinimum(node->left);
		return node;
	}

	Node <T> * treeMaximum(Node <T> * node) {
		if (node->right != this->NIL)
			return treeMaximum(node->right);
		return node;
	}

	Node <T> * search(T key) {	// page 311
		Node <T> * p = this->root;
		while (p != NIL) {
			T k = p->getKey();
			if (k == key) {
				return p;
			} else if (key < k) {
				p = p->left;
				continue;
			} else {
				p = p->right;
				continue;
			}
		}
		return p;
	}

	Node <T> * osSelect(unsigned int i) {
		return osSelect(this->root, i);
	}

	Node <T> * osSelect(Node<T> * node, unsigned int i) { // page 341
		unsigned int r = node->left->getSize() + 1;
		if (i == r) {
			return node;
		} else if (i < r) {
			return osSelect(node->left, i);
		} else {
			return osSelect(node->right, i - r);
		}
	}

	unsigned int osRank (Node<T> * node) {
		unsigned int r = node->left->getSize() + 1;
		Node <T> * y = node;
		while (y != this->NIL) {
			if (y == y->parent->right) {
				r = r + y->parent->left->getSize() + 1;
			}
			y = y->parent;
		}
		return r;
	}

	void print() {
		cout	<< "\nROOT/COLOR/SIZE: " << this->root->getKey() << '/' 
				<< (this->root->getColor() ? "RED" : "BLACK") << '/' 
				<< this->root->getSize() << endl;
		cout 	<< "NIL/COLOR/SIZE: " << this->NIL->getKey() << '/' 
				<< (this->NIL->getColor() ? "RED" : "BLACK") << '/' 
				<< this->NIL->getSize() << endl;
		print(this->root);
		cout << endl;
	}	
	void print(Node<T> * node) {
		if (node != this->NIL) {
			print(node->left);
			cout << node->getKey() << '/' << (node->getColor() ? 'R' : 'B') << '/' << node->getSize() << '\t';
			print(node->right);
		}
	}
	/*
	void printTree() {
		printTree(this->root);
	}

	void printTree(Node<T> * node) {
		if (node != NIL) {
			printTree(node->left);
			printTree(node->right);
			printValues(node);
		}

	}
	void printValues(Node<T> * node) {
		cout << node->getKey() << '/' << (node->getColor() ? 'R' : 'B') << '/' << node->getSize() << '\t';
	}	
	*/
};


#endif