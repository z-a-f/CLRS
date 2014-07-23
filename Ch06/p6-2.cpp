#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./heapSort.hpp"

int child_D (int d, int parentNum, int childNum) {
	assert(childNum > 0 && childNum <= d);
	int child = d * parentNum + childNum;
	return child;
	
	// Approach:
	// A[0] -> {A[1], A[2], ..., A[d]}
	// A[1] -> {A[d+1], A[d+2], ..., A[2d]}
	// A[2] -> {A[2d+1], A[2d+2, ..., A[3d]}
	// A[3] -> {A[3d+1], A[3d+2], ..., A[4d]}
	// A[i] -> {A[di + j]}, where i is the parentNum, j is the childNum	
}

int parent_D (int d, int i) {
	// Approach:
	// A[1], ..., A[d] -> A[0]
	// A[d+1], ..., A[2d] -> A[1]
	// A[di+j] -> A[i], given j <= d
	// ==> parent = ceil(i/d)-1
	int parent = ceil(i/d) - 1;
	return parent;
}

int heapMaximum_D(vector<int> A) {
	return A.at(0);
}

void maxHeapify_D (vector<int> *A, int i, int d, int heapSize) {
	int len = A->size();
	int largest = i; // = INT_MIN;
	int c;
	// Iterate through children
	for (int child = 1; child <= d; child++) {
		c = child_D(d, i, child);
		if (c <= heapSize && A->at(c) > A->at(largest)) {
			largest = c;
		}
	}
	if (largest != i) {
		swap(A->at(i), A->at(largest));
		maxHeapify_D(A, largest, d, heapSize);
	}
}

void buildMaxHeap_D(vector<int> *A, int d) {
  int len = A->size();
  for (int i = (len / d); i >= 0; i--) {
    maxHeapify_D(A, i, d, len-1);
  }
}

int heapExtractMax_D(vector<int> *A, int d) {
	// int heapSize = A->size() - 1;
	// assert(heapSize >= 0);
	int max = A->at(0);
	// A->at(0) = A->at(heapSize);	// It's better to get rid of the element in the heap
	A->erase(A->begin());
	// heapSize--;
	buildMaxHeap_D(A, d);
	return max;
}

void heapSort_D(vector<int> *A, int d) {
  int len = A->size();
  int heapSize = len-1;
  buildMaxHeap_D(A, d);
  for (int i = len-1; i > 0; i--) {
    swap(A->at(0), A->at(i));
    heapSize--;
    maxHeapify_D(A, 0, d, heapSize);
  }
  
}

int main () {
	int ar[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 100, 12, 34, 111, 56};
	vector<int> A;
	A.insert(A.begin(), ar, ar+15);
	
	printVector(A);
	buildMaxHeap_D(&A, 3);
	printVector(A);
	heapSort_D (&A, 3);
	printVector(A);
	// cout << A.size() << endl;
	
}