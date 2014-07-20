#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#include "../support/myFunctions.hpp"	// For swap, printVector, etc.
#include "./heapSort.hpp"	// For heapsort



int main() {
	int ar[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	vector<int> A;
	A.insert(A.begin(), ar, ar+10);
	
	cout << "Original: ";
	vectorPrint(A);
	
	vector<int> B = A;
	
	cout << "Recursive: ";
	buildMaxHeap (&A);
	printVector(A);
	
	cout << "Loop: ";
	buildMaxHeapLoop(&B);
	printVector(B);
	
	
	

}