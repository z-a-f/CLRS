/* BEGIN: Hash functions */
int hashDivision (int key, int TABLE_SIZE) {
	return key % TABLE_SIZE;
}

int hashMultiplication (int key, int TABLE_SIZE) {
	int p = (int)ceil(log2(TABLE_SIZE));
	int omega = 32;
	long long MASK = ((long long)1 << omega) - 1.0;

	double A = 0.6180339887;	// Knuth suggests this number
	double s = A * ((long long)1 << omega);
	long long ks = (long long)(1.0 * key * s);
	ks = (ks & MASK) >> (omega - p);
	return ks;
}
/**/
int hashAuxiliary(int key, int TABLE_SIZE, int option) { // For easy selection
	switch (option) {
		case 0: 
			return hashDivision(key, TABLE_SIZE);
		case 1:
			return hashMultiplication(key, TABLE_SIZE);
		default:
			cout << "INCORRECT OPTION" << endl;
			exit(1);
	}
}

int hashLinearProbing (int key, int i, int TABLE_SIZE) {
	return (hashAuxiliary(key, TABLE_SIZE, 0) + i) % TABLE_SIZE;
}

int hashQuadraticProbing (int key, int i, int TABLE_SIZE) {
	const int c1 = 17; // Whatever
	const int c2 = 19; // Whatever
	return (hashAuxiliary(key, TABLE_SIZE, 0) + c1*i + c2*i) % TABLE_SIZE;
}

int hashDouble (int key, int i, int TABLE_SIZE) {
	// Can we choose the linear and the quadratic?
	int hash1 = hashAuxiliary(key, TABLE_SIZE, 0);
	int hash2 = hashAuxiliary(key, TABLE_SIZE, 1);
	return (hash1 + i*hash2) % TABLE_SIZE;
}
/* END: Hash functions */


// Hash entry class (for storing individual elements):
template <typename T>
class HashEntry {
private:
	int key;	// Key for the value
	T value;	// The value to be stored
public:
	// Keeping the next public for simplicity (otherwise need to write getNext() and setNext())
	HashEntry <T> * next; // Next value in the chain
	HashEntry <T> * prev; // Previous value in the chain

	// Constructor:
	HashEntry(int key, T value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
	HashEntry(string str, T value) {
		int key = 0;
		for (int i = 0; i < str.length(); i++) {
			key += (int)str[i];
		}
		this->key = key;
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
	HashEntry() {
		this->next = NULL;
		this->prev = NULL;
	}

	// Get the key:
	int getKey() {
		return key;
	}

	// Get the value:
	T getValue() {
		return value;
	}

	/* Get the next value:
	HashEntry<T> * getNext() {
		return next;
	} */
};

// Hash table class:
template <typename T>
class HashTable {
private:
	HashEntry <T> **table; // Array of pointers
	unsigned int TABLE_SIZE;	// Works best if this is prime, far from any power of 2
public:
	// Constructor:
	HashTable(unsigned int TABLE_SIZE) {
		// Store the size:
		this->TABLE_SIZE = TABLE_SIZE;
		// Create a table:
		this->table = new HashEntry<T>*[TABLE_SIZE];
		// NULLify all the pointers:
		for (int i = 0; i < TABLE_SIZE; i++) {
			this->table[i] = NULL;
		}
	}
	// Destructor:
	~HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++){
			if (table[i] != NULL)
				delete table[i];
		}
		delete [] table;
 	}
 	
 	int hash(int key) {
 		return hashDivision(key, TABLE_SIZE);
 	}

 	void chainedHashInsert(HashEntry <T> * entry) {
 		// Using singly linked list
 		int h = hash(entry->getKey());
 		entry->next = table[h];
 		if (table[h] != NULL) {
 			table[h]->prev = entry;
 		}
 		table[h] = entry;
 		entry->prev = NULL;
 	}

 	HashEntry<T> *chainedHashSearch (int key) {
 		// Search for an element and return a pointer to it
 		int h = hash(key);
 		HashEntry<T> *p;
 		p = table[h];
 		while (p != NULL && p->getKey() != key) // WOW! order matters!!!
 			p = p->next;
 		return p;
 	}

 	HashEntry<T> *chainedHashSearch (string str) {
 		int key = 0;
		for (int i = 0; i < str.length(); i++) {
			key += (int)str[i];
		}
 		// Search for an element and return a pointer to it
 		int h = hash(key);
 		HashEntry<T> *p;
 		p = table[h];
 		while (p != NULL && p->getKey() != key) // WOW! order matters!!!
 			p = p->next;
 		return p;
 	}

 	void chainedHashDelete (HashEntry <T> *entry) {
 		int h = hash(entry->getKey());
 		if (entry->prev != NULL) {
 			entry->prev->next = entry->next;
 		} else {
 			table[h] = entry->next;
 		}
 		if (entry->next != NULL) {
 			entry->next->prev = entry->prev;
 		}
 		free (entry);
 	}

 	void print () {
 		if (table == NULL) {
 			cout << "NULL\n";
 		} else {
 			HashEntry<T> *p = new HashEntry<T>;
 			for (int i = 0; i < TABLE_SIZE; i++) {
 				p = table[i];
 				cout << i << "\t";
 				while (p != NULL) {
 					cout << " <-> {" << p->getKey() << "," << p->getValue() << "}";
 					p = p->next;
 				}
 				cout << " <-> NULL" << endl;
 			}
 		}
 	}

};

//////////////////////////////////////////////////////////////////////////////////////
// OPEN ADDRESSING

// Hash entry class (for storing individual elements):
template <typename T>
class HashEntryOA {
private:
	int key;	// Key for the value
	bool deleted; // was it deleted?
	T value;	// The value to be stored
public:
	// Constructor:
	HashEntryOA(int key, T value) {
		this->key = key;
		this->value = value;
		this->deleted = false;
	}
	HashEntryOA(string str, T value) {
		int key = 0;
		for (int i = 0; i < str.length(); i++) {
			key += (int)str[i];
		}
		this->key = key;
		this->value = value;
		this->deleted = false;
	}

	// Get the key:
	int getKey() {
		return key;
	}

	// Get the value:
	T getValue() {
		return value;
	}

	// is deleted?
	bool isDeleted() {
		return deleted;
	}
};

template <typename T> 
class HashTableOA {
private:
	HashEntryOA <T> **table; // Array of pointers
	unsigned int TABLE_SIZE;	// Works best if this is prime, far from any power of 2
public:
	// Constructor:
	HashTableOA(unsigned int TABLE_SIZE) {
		// Store the size:
		this->TABLE_SIZE = TABLE_SIZE;
		// Create a table:
		this->table = new HashEntryOA<T>*[TABLE_SIZE];
		// NULLify all the pointers:
		for (int i = 0; i < TABLE_SIZE; i++) {
			this->table[i] = NULL;
		}
	}
	// Destructor:
	~HashTableOA() {
		for (int i = 0; i < TABLE_SIZE; i++){
			if (table[i] != NULL)
				delete table[i];
		}
		delete [] table;
 	}

 	int hash(int key, int i) {
 		return hashLinearProbing(key, i, TABLE_SIZE);
 	}
 	
 	int hashInsert(HashEntryOA <T> entry) { // Different from the book, as I want to store the value as well
 		int i = 0;
 		while (i != TABLE_SIZE) {
 			int j = hash(entry->getKey(), i);
 			if (table[j]->isDeleted() || table[j] == NULL) {
 				table[j] = entry;
 				return j;
 			} else {
 				i++;
 			}
 		}
 		cout << "(OVERFLOW) HASHTABLE FULL!\n";
 		return -1;
 	}

 	int hashSearch(int key) {
 		int i = 0;
 		int j;
 		do {
 			j = hash(key, i);
 			if (table[j]->isDeleted()) continue;
 			if (table[j]->getKey() == key) return j;
 			i++;
 		} while (table[j] != NULL && i != TABLE_SIZE);
 		return -1;
 	}

};




