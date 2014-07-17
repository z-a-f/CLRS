#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void vectorPrint (vector<int> A) {
  for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int i) {
  return (i - 1) >> 1;	// floor((i-1)/2)
}   

int left(int i) {
  return (i << 1) + 1;	// 2 * i + 1
}

int right(int i) {	// 2 * (i + 1)
  return (i + 1) << 1;
}

void maxHeapify (vector<int> *A, int i, int heapSize) {
  int l = left(i);
  int r = right(i);
  int largest;
  int temp;
  if (l <= heapSize && A->at(l) > A->at(i)) {
    largest = l;
  } else {
    largest = i;
  }

  if (r <= heapSize && A->at(r) > A->at(largest)) {
    largest = r;
  }

  if (largest != i) {
    swap(A->at(i), A->at(largest));
    // temp = A->at(i);
    // A->at(i) = A->at(largest);
    // A->at(largest) = temp;
    maxHeapify(A, largest, heapSize);
  }
}

void buildMaxHeap(vector<int> *A) {
  int len = A->size();
  for (int i = (len >> 1); i >= 0; i--) {
    maxHeapify(A, i, len-1);
  }
}

void heapSort(vector<int> *A) {
  int len = A->size();
  int heapSize = len-1;
  buildMaxHeap(A);
  for (int i = len-1; i > 0; i--) {
    swap(A->at(0), A->at(i));
    heapSize--;
    maxHeapify(A, 0, heapSize);
  }
  
}

int main() {
  int ar[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  vector<int> A;
  A.insert(A.begin(), ar, ar+10);
  vectorPrint(A);
  // buildMaxHeap(&A);
  // vectorPrint(A);
  heapSort(&A);
  vectorPrint(A);
}
