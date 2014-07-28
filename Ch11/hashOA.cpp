#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./hash.hpp"

int main() {
	HashTableOA <int> ht(8);

	HashEntryOA<int> *E0 = new HashEntryOA<int>(0, 10);
	HashEntryOA<int> *E1 = new HashEntryOA<int>(8, 11);

	ht.hashInsert(E0);
	ht.hashInsert(E1);
	ht.print();

	cout << endl;
	ht.hashInsert(new HashEntryOA<int>(16, 1));
	ht.hashInsert(new HashEntryOA<int>(5, 7));
	ht.print();

	cout << endl;
	HashEntryOA<int> *k = ht.hashSearch(8);
	if (k != NULL)
		cout << k->getValue() << endl;

	
	cout << endl;
	ht.hashDelete(k);
	ht.print();

	cout << endl;
	ht.hashInsert(new HashEntryOA<int>(32, 3));
	ht.print();

}