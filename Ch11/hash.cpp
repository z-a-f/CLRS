#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./hash.hpp"

int main() {
	HashTable <int> ht(8);

	HashEntry<int> *E0 = new HashEntry<int>(0, 10);
	HashEntry<int> *E1 = new HashEntry<int>(8, 11);

	ht.chainedHashInsert(E0);
	ht.chainedHashInsert(E1);

	ht.print();

	cout << endl;
	HashEntry<int> *p = ht.chainedHashSearch(0);
	if (p != NULL)
		cout << "FOUND: {" << p->getKey() << ", " << p->getValue() << "}" << endl;

	ht.chainedHashDelete(p);
	ht.print();

	cout << endl;
	ht.chainedHashInsert(new HashEntry<int> (3, 12));
	ht.print();

	cout << endl;
	ht.chainedHashInsert(new HashEntry<int> (30303030, 12));
	ht.print();


	cout << endl << endl;
	HashTable <int> htString(8);
	HashEntry<int> *E2 = new HashEntry<int>("zafar", 10);
	HashEntry<int> *E3 = new HashEntry<int>("abcdef", 11);
	htString.chainedHashInsert(E2);
	htString.chainedHashInsert(E3);

	htString.print();
	cout << endl;
	p = htString.chainedHashSearch("zafar");
	if (p != NULL)
		cout << "FOUND: {" << p->getKey() << ", " << p->getValue() << "}" << endl;

}