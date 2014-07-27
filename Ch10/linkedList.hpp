
template <typename T> class Node {
public:
	T key;
	Node *next;
	Node *prev;

	// no arg constructor:
	Node() {
		next = NULL;
		prev = NULL;
	}
	// arg constructor:
	Node (T key) {
		this->key = key;
		next = NULL;
		prev = NULL;
	}
	T get() {	// Breaks if the Node = NULL
		return key;
	}
};

// No tail so far:
template <typename T> class lList {
private:
	Node <T> *head;
public:
	// Constructor:
	lList() {
		this->head = NULL;
	}

	Node <T> * getHead() {
		return head;
	}

	Node <T> * getTail() {
		// If tail exists, just return it
		Node <T> *it = new Node<T>;
		it = head;
		while(it->next != NULL) {
			it = it->next;
		}
		return it;
	}

	void setTail(Node<T> *x) {
		Node<T> * it = new Node<T>;
		it = getTail();
		it->next = x;
	}

	// Search the list for a key:
	Node<T>* search(T key) {
		Node <T> *x = new Node<T>;
		x = head;
		while (x != NULL && x->key != key) {
			x = x->next;
		}
		return x;
	}

	// Insert an existing node:
	void insertNode(Node <T> *x) {
		x->next = head;
		if (head != NULL) {
			head->prev = x;
		} 
		head = x;
		x->prev = NULL;
	}

	// Insert a new key:
	void insertKey(T key) {
		Node <T> *x = new Node <T>(key);
		insertNode(x);
	}

	// Remove a node:
	void deleteNode(Node <T> *x) {
		if(x->prev != NULL) { // If there is something before x
			x->prev->next = x->next;
		} else {
			head = x->next;
		}
		if (x->next != NULL) { // if there is something after x
			x->next->prev = x->prev;
		}
		// free x:
		free(x);
	}

	void print() {
		Node <T> *p;
		p = head;
		cout << "NULL->";
		while (p != NULL) {
			cout << p->key << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
};

template <typename T> class lListSent {	// Use sentinel instead of head and tail
private:
	Node <T> *NIL;
public:
	lListSent() {
		NIL->next = NIL;
		NIL->prev = NIL;
	}

	void deleteNode(Node<T> *x) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}

	Node <T> *search(T key) {
		Node <T> *x = new Node<T>;
		x = NIL->next;
		while(x != NIL && x->key != key) {
			x = x->next;
		}
		return x;
	}

	void insertNode(Node<T> *x) {
		x->next = NIL->next;
		NIL->next->prev = x;
		NIL->next = x;
		x->prev = NIL;
	}

	void insertKey(T key) {
		Node <T> *x = new Node<T>(key);
		insertNode(x);
	}

	void print() {
		Node <T> *p = new Node<T>;
		p = NIL->next;
		cout << "NIL";
		while (p != NIL) {
			cout << "<-->" << p->key;
			p = p->next;
		} 
		cout << "<-->NIL" << endl;
	}
};

/////////////////////////////////////////////////////////////////
// Methods:

template <typename T> 
lList<T> UNION (lList<T> L1, lList<T> L2) {
	lList<T> final;
	final = L1;
	/* If tail exists:
		// set the tail of L1 to b equal to the head of L2
	*/
	// Find the end of the L1:
	final.setTail(L2.getHead());
	return final;
};

