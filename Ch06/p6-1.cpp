#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./heapSort.hpp"

void heapIncreaseKeyPrime (vector<int> *A, int i, int key) {
	// assert(key >= A->at(i));
	A->at(i) = key;
	while (i > 0 && A->at(parent(i)) < A->at(i)) {
		swap (A->at(i), A->at(parent(i)));
		i = parent(i);
	}
}

void maxHeapInsertPrime(vector<int> *A, int key, int *heapSize) {
	// A->at(heapSize) = INT_MIN;		// Requires <climits> or <limits.h>
	*heapSize = *heapSize+1;
	A->push_back(INT_MIN);
	heapIncreaseKeyPrime(A, *heapSize, key);
}

void buildMaxHeapPrime(vector<int> *A) {
	int heapSize = 1;
	int len = A->size();
	for (int i = 1; i < len; i++) {
		maxHeapInsertPrime (A, A->at(i), &heapSize);
	}
}

int main () {
	int ar[12] = {13, 15, 9, 17, 12, 8, 7, 4, 0, 6, 2, 1};
	vector<int> A, B;
	A.insert(A.begin(), ar, ar + 12);
	B = A;
	
	
	cout << "SOLUTION A):" << endl;
	cout << "Original vector:" << endl;
	printVector(A);
	
	cout << "buildMaxHeap:" << endl;
	buildMaxHeap(&A);
	printVector(A);
	
	cout << "buildMaxHeapPrime:" << endl;
	buildMaxHeapPrime(&B);
	printVector(B);
}