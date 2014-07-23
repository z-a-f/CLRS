#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./heapSort.hpp"

void reshapeHeap_tableau (vector<int> *A, int x, int y) {
	int len = A->size();
	int tab = x*y;
	assert (len <= tab);
	while (tab != len) {
		A->push_back(INT_MAX);
		len++;
	}
}

int right_tableau (int i, int x) {
	int right = i+1;
	if (right % x) {
		return right;
	} else {
		return i;
	}
}

int down_tableau (int i, int x, int y) {
	int down = i + y;
	if (down >= x*y) {
		return i;
	} else {
		return down;
	}
}	

void maxHeapify_tableau (vector<int> *A, int i, int x, int y, int heapSize) {
  int d = down_tableau(i, x, y);
  int r = right_tableau(i, x);
  int smallest;
  int temp;
  if (d <= heapSize && A->at(d) < A->at(i)) {
    smallest = d;
  } else {
    smallest = i;
  }

  if (r <= heapSize && A->at(r) < A->at(smallest)) {
    smallest = r;
  }

  if (smallest != i) {
    swap(A->at(i), A->at(smallest));
    // temp = A->at(i);
    // A->at(i) = A->at(largest);
    // A->at(largest) = temp;
    maxHeapify_tableau(A, smallest, x, y, heapSize);
  }
}

void buildMaxHeap_tableau(vector<int> *A, int x, int y) {
  int len = A->size();
  for (int i = (len >> 1); i >= 0; i--) {
    maxHeapify_tableau(A, i, x, y, len-1);
  }
}

bool isInTableau(vector<int> A, int val) {
	int len = A.size();
	for (int i = 0; i < len && A.at(i) != INT_MAX; i++) {
		if (A.at(i) == val)
			return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////

void printTableau(vector<int> A, int x, int y) {
	int first = 0;
	int current = first;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (A.at(current) == INT_MAX)
				cout << "inf\t";
			else
				cout << A.at(current) << '\t';
			current = right_tableau(current, x);
		}
		first = down_tableau(first, x, y);
		current = first;
		cout << endl;
	}
}

int main() {
	int ar[9] = {9,16,3,2,4,8,5,14,12};
	vector<int> A;
	A.insert(A.begin(), ar, ar+9);
	printVector(A);
	reshapeHeap_tableau (&A, 4, 4);
	printVector(A);
	maxHeapify_tableau (&A, 0, 4, 4, 15);
	printVector(A);
	buildMaxHeap_tableau(&A, 4, 4);
	printVector(A);
	printTableau(A, 4, 4);
	cout << isInTableau(A, 23) << endl;
		
}