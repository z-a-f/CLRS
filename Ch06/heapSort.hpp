#ifndef __HEAP_SORT__
#define __HEAP_SORT__

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

void maxHeapifyLoop (vector<int> *A, int i, int heapSize) {
	// Woops that's broken
	int l, r;
	int largest = i;
	do {
		swap(A->at(i), A->at(largest));
		l = left(i);
		r = right(i);
		if (l <= heapSize && A->at(l) > A->at(i)) {
			largest = r;
		} else {
			largest = i;
		}
		if (r <= heapSize && A->at(r) > A->at(largest)) {
    		largest = r;
 		}
	} while (largest != i);
}


void buildMaxHeap(vector<int> *A) {
  int len = A->size();
  for (int i = (len >> 1); i >= 0; i--) {
    maxHeapify(A, i, len-1);
  }
}

void buildMaxHeapLoop(vector<int> *A) {
  int len = A->size();
  for (int i = (len >> 1); i >= 0; i--) {
    maxHeapifyLoop(A, i, len-1);
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

////////////////////////////////////////////////////////////////////////////////////////

int heapMaximum(vector<int> A) {
	return A.at(0);
}

int heapExtractMax(vector<int> A) {
	int heapSize = A.size() - 1;
	assert(heapSize >= 1);
	
	int max = A.at(0);
	A.at(0) = A.at(heapSize);
	heapSize--;
	maxHeapify(A, 0, heapSize);
	return max;
}

////////////////////////////////////////////////////////////////////////////////////////
// For p6-1
heapIncreaseKey (vector<int> *A, int i, int key) {
	assert(key < A->at(i));
}

maxHeapInsert(vector<int> A, int key) {
	
}


#endif