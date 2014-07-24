#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./quickSort.hpp"

void tailRecursiveQuickSort(vector<int> *A, int p, int r) {
	int q;
	while (p < r) {
		q = partition(A, p, r);
		tailRecursiveQuickSort(A, p, q-1);
		p = q + 1;
	}
}

int main() {
	int ar[12] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
	vector<int> A;
	A.insert(A.begin(), ar, ar+12);
	
	printVector(A);
	tailRecursiveQuickSort(&A, 0, A.size()-1);
	printVector(A);
}