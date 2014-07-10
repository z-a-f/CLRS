#include <iostream>
#include <vector>

#include "myFunctions.h"

using namespace std;

int main () {
	static const int ar[] = {31, 41, 59, 26, 41, 58};
	vector<int> A (ar, ar + sizeof(ar) / sizeof(ar[0]));
	insertionSortPrint(&A, 6);
	//printVector (A);
}