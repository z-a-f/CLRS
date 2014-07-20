#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#include "../support/myFunctions.hpp"	// For swap, printVector, etc.
#include "./heapSort.hpp"	// For heapsort

int main() {
	int ar[10] = {23, 17, 14, 6,13, 10, 1, 5, 7, 12};
	vector<int> V;
	V.insert(V.begin(), ar, ar+10);
	printVector(V);
	buildMaxHeap(&V);
	printVector(V);
	
}