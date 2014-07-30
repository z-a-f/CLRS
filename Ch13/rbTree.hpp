#ifndef RBTREE_H_
#define RBTREE_H_


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
		this->key = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	Node(Node <T> * NIL) {
		this->color = _BLACK_;
		this->key = 0;
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

	Node <T> * search(T key) {
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


#endif