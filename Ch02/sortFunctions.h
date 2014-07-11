#ifndef __MY__INCLUDES__H
#include "myIncludes.h"
#endif

#ifndef __MY__OTHER__FUNCTIONS__H
#include "otherFunctions.h"
#endif
////////////////////////////////////////////////////////////////////////////////////////

void insertionSort(std::vector<int> *ar, int len) {
    int key;
    for (int j = 1, i; j < len; j++) {
        key = ar->at(j);
        // insert ar[j] into the stored sequency ar[0...j-1]:
        i = j - 1;
        while (i >= 0 && ar->at(i) > key) {     // Array starts from 0, so it's different from the book
            ar->at(i+1) = ar->at(i);
            i--;
        }
        ar->at(i+1) = key;
    }
}

void insertionSortReverse(std::vector<int> *ar, int len) {	// p2.1-2
    int key;
    for (int j = 1, i; j < len; j++) {
        key = ar->at(j);
        i = j - 1;
        while (i >= 0 && ar->at(i) < key) {		// Single change
            ar->at(i+1) = ar->at(i);
            i--;
        }
        ar->at(i+1) = key;
    }
}

void insertionSortPrint(std::vector<int> *ar, int len) {
	// Use this for loop invariant
    int key;
    for (int j = 1, i; j < len; j++) {
        key = ar->at(j);
        // insert ar[j] into the stored sequency ar[0...j-1]:
        i = j - 1;
        while (i >= 0 && ar->at(i) > key) {     // Array starts from 0, so it's different from the book
        	std::cout << "j, i: " << j << i << "\t Key: " << key << "\t";
        	printVector(*ar);
            ar->at(i+1) = ar->at(i);
            i--;
        }
        ar->at(i+1) = key;
    }
}

void insertionSortRange(std::vector<int> *ar, int p, int r) {
    int key;
    int len = r - p + 1;
    for (int j = 1, i; j < len; j++) {
        key = ar->at(j + p);
        // insert ar[j] into the stored sequency ar[0...j-1]:
        i = j - 1;
        while (i >= 0 && ar->at(i) > key) {     // Array starts from 0, so it's different from the book
            ar->at(i + 1 + p) = ar->at(i + p);
            i--;
        }
        ar->at(i + 1 + p) = key;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

void selectionSort(std::vector<int> *ar, int len) {
	int min;
	
	for (int i = 0; i < len - 1; i++) {
		min = i;
		// Find the min:
		for (int j = i + 1; j < len; j++) {
			if (ar->at(j) < ar->at(min)) {
				min = j;
			}
		}
		if (min != i){
			swap(&ar->at(min), &ar->at(i));

		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////

void merge(std::vector<int> *ar, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<int> L;
	std::vector<int> R;
	
	for (int i = 0; i < n1; i++) {
		L.push_back(ar->at(p + i));
	}
	for (int i = 0; i < n2; i++) {
		R.push_back(ar->at(q + i + 1));
	}
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);
	
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			ar->at(k) = L[i];
			i++;
		} else {
			ar->at(k) = R[j];
			j++;
		}
	}
}

void mergeSort(std::vector<int> *ar, int p, int r) {

	int q;
	if (p < r) {
		q = floor((p+r) / 2.0);
		mergeSort(ar, p, q);
		mergeSort(ar, q+1, r);
		merge(ar, p, q, r);
	}
}

void mergeNoSent(std::vector<int> *ar, int p, int q, int r) { // For p2.3-1
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<int> L;
	std::vector<int> R;
	
	for (int i = 0; i < n1; i++) {
		L.push_back(ar->at(p + i));
	}
	for (int i = 0; i < n2; i++) {
		R.push_back(ar->at(q + i + 1));
	}
	
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if(i < n1 && j < n2) {
			if ( L[i] <= R[j] ) {
				ar->at(k) = L[i];
				i++;
			} else {
				ar->at(k) = R[j];
				j++;
			}
		} else if (i >= n1 && j < n2) {
			// Copy R to the ar:
			std::copy(R.begin() + j, R.end(), ar->begin() + k);
			return;
		} else if (i < n1 && j >= n2) {
			std::copy(L.begin() + i, L.end(), ar->begin() + k);
			return;
		} else {
			return;
		}
	}
}

void mergeSortNoSent(std::vector<int> *ar, int p, int r) { // For p2.3-1
	int q;
	if (p < r) {
		q = floor((p+r) / 2.0);
		mergeSortNoSent(ar, p, q);
		mergeSortNoSent(ar, q + 1, r);
		mergeNoSent(ar, p, q, r);
	}
}

void mergeInsertionSort (std::vector<int> *ar, int p, int r, int k) {
	if (r - p <= k) {
		insertionSortRange(ar, p, r);
		return;
	}

	int q;
	if (p < r) {
		q = floor((p+r) / 2.0);
		mergeInsertionSort(ar, p, q, 3);
		mergeInsertionSort(ar, q+1, r, 3);
		merge(ar, p, q, r);
	}
}

////////////////////////////////////////////////////////////////////////////////////////

void bubbleSort (std::vector<int> *ar, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = len - 1; j > i; j--) {
			if (ar->at(j) < ar->at(j-1)) {
				swap (&ar->at(j), &ar->at(j-1));
			}
		}
	} 
}