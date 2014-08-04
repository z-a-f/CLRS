#ifndef RBTREE_INTERVAL_H_
#define RBTREE_INTERVAL_H_
/* Interval version of the red-black tree data structure */

#define _RED_	true
#define _BLACK_	false

template <typename T>
class interval {	// Should I use struct instead?
public:
	T low;
	T high;

	void set(T low, T high) {
		this->low = low;
		this->high = high;
	}
	void print () {
		cout << '{' << this->low << ',' << this->high << '}';
	}
};

template <typename T>
class iNode {
private:
	// T key;
	interval<T> key;
	bool color;	// 0-> black, 1->red
	unsigned int size;	// Size of the current node
	T MAX;	// max of the current node
public:
	iNode<T> * left;
	iNode<T> * right;
	iNode<T> * parent;
	
	iNode() {
		this->color = _BLACK_;
		this->key.low = 0;
		this->key.high = 0;
		this->size = 0;
		this->MAX = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	iNode(iNode <T> * NIL) {
		this->color = _BLACK_;
		this->key.low = 0;
		this->key.high = 0;
		this->size = 0;
		this->MAX = 0;
		this->left = NIL;
		this->right = NIL;
		this->parent = NIL;
	}
	iNode(interval<T> key) {
		this->color = _BLACK_;
		this->key = key;
		this->size = 0;
		this->MAX = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	iNode(T low, T high) {
		this->color = _BLACK_;
		this->key.low = low;
		this->key.high = high;
		this->size = 0;
		this->MAX = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	
	~iNode() {
		/*
		delete left;
		delete right;		
		*/
	}
	
	interval<T> getKey() {
		return this->key;
	}
	void setKey(interval<T> key) {
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
	T getMax() {
		return this->MAX;
	}
	void setMax(T MAX) {
		this->MAX = MAX;
	}

	void updateMax() {
		T temp;
		if (this->left->getMax() < this->right->getMax()) {
			temp = this->right->getMax();
		} else {
			temp = this->left->getMax();
		}

		if (this->MAX >= temp) {
			return;
		} else {
			this->MAX = temp;
		}
	}
};

template <typename T>
class rbTreeI {
protected:
	iNode<T> * root;
	iNode<T> * NIL; // sentinel
	void treeDelete(iNode <T> * node) {
		// Use postorder tree walk to delete the entries
		if (node != NULL && node != NIL) {
			treeDelete(node->left);
			treeDelete(node->right);
			delete node;
		}
	}
	void NULL2NIL(iNode<T> * node) {
		// replace NULL's with NIL's
		if (node->left == this->NIL) {
			return;
		} else if (node->left == NULL) {
			node->left = this->NIL;
			return;
		} else {
			NULL2NIL(node->left);
		}
		if (node->right == this->NIL) {
			return;
		} else if (node->right == NULL) {
			node->right = this->NIL;
			return;
		} else {
			NULL2NIL(node->right);
		}
	}
public:
	rbTreeI() {
		// this->root = new iNode<T>;
		this->NIL = new iNode<T>;
		
		/* Set the NIL to point to itself */
		this->NIL->parent = this->NIL;
		this->NIL->left = this->NIL;
		this->NIL->right = this->NIL;
		this->NIL->setSize(0);
		this->NIL->setMax(0);
		this->NIL->setColor(_BLACK_);

		this->root = this->NIL;
	}
	rbTreeI(iNode<T> * node) {
		this->root = node;
		this->root->parent = this->NIL;
		NULL2NIL(this->root);
	}
	
	~rbTreeI() {
		// delete this->root->parent;
		treeDelete(this->root);
		delete this->NIL;
	}

	// Insert Function - adapted from rbTree.hpp
	void insert (iNode<T> * z) {  // page 315
		// Assume all keys are distinct!
		z->setSize(1);
		iNode <T> * y = this->NIL;
		iNode <T> * x = this->root;
		while (x != this->NIL) {
			x->setSize(x->getSize()+1);
			y = x;
			if (z->getKey().low < x->getKey().low) {
				x = x->left;
			} else {
				x = x->right;
			}
		}
		z->parent = y;
		if (y == this->NIL) {
			this->root = z;
		} else if (z->getKey().low < y->getKey().low) {
			y->left = z;
		} else {
			y->right = z;
		}
		z->left = this->NIL;
		z->right = this->NIL;
		z->setColor(_RED_);

		insertFixup(z);
		updateMax(z);
	}

	void insertFixup(iNode <T> * z) {	// page 316
		iNode <T> * y;
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

	void updateMax(iNode <T> * node) {
		if (node != this->NIL){
			node->updateMax();
			updateMax(node->parent);
		}
	}

	void leftRotate(iNode<T> *x) {	// page 313
		iNode<T> * y = x->right;	// set y
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
		// Update maximum:
		x->updateMax();
		y->updateMax();
	}
	
	void rightRotate(iNode<T> *x) { // page 313
		iNode<T> * y = x->left;
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
		// Update maximums
		x->updateMax();
		y->updateMax();
	}

	void print() {
		cout	<< "\nROOT/COLOR/SIZE/MAX: "; this->root->getKey().print();
		cout	<< '/' 
				<< (this->root->getColor() ? "RED" : "BLACK") << '/' 
				<< this->root->getSize() << '/'
				<< this->root->getMax() << endl;
		cout 	<< "NIL/COLOR/SIZE/MAX: "; this->NIL->getKey().print();
		cout 	<< '/' 
				<< (this->NIL->getColor() ? "RED" : "BLACK") << '/' 
				<< this->NIL->getSize() << '/'
				<< this->NIL->getMax() << endl;
		print(this->root);
		cout << endl;
	}	
	void print(iNode<T> * node) {
		if (node != this->NIL) {
			print(node->left);
					node->getKey().print(); 
			cout << '/' << (node->getColor() ? 'R' : 'B') << '/' 
					<< node->getSize() << '/'
					<< node->getMax() << '\t';
			print(node->right);
		}
	}
};


#endif