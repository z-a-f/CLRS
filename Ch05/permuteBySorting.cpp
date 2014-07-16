#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

using namespace std;

#include "randomRange.hpp"

void printVector(vector<int> A) {
	for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
		cout << *it << ' ';	
	}
	cout << endl;
}

void bubbleSortKV (vector<int> *K, vector<int> *V, int n) {
	int newn;
	int temp;
	do {
		newn = 0;
		for (int i = 1; i < n; i++) {
			if (K->at(i-1) > K->at(i)) {
				// Swap the keys:
				temp = K->at(i);
				K->at(i) = K->at(i-1);
				K->at(i-1) = K->at(i);
				// Swap the values:
				temp = V->at(i);
				V->at(i) = V->at(i-1);
				V->at(i-1) = V->at(i);
				
				newn = i;
			}
		}
		n = newn;
	} while (n != 0);
}

void permuteBySorting(vector<int> *A) {
	int n = A->size();
	int max = pow(n, 3);
	vector<int> P;
	for (int i = 0; i < n; i++)
		P.push_back(randomRange(1, max));

	// Sort A using P as keys (lazy bubble sort):
	bubbleSortKV (&P, A, n);
	
	printVector (P);	
}



int main () {
	srand(time(NULL));
	vector<int> A;
	for (int i = 10; i > 0; i--) {
		A.push_back(i);
	}
	
	printVector(A);
	
	permuteBySorting(&A);
	
	printVector(A);
}