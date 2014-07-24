#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./quickSort.hpp"

int hoarePartition_Print(vector<int> *A, int p, int r) {
	int x = A->at(p);
	int i = p - 1;
	int j = r + 1;
	while (true) {
		cout << "\tx: " << x;
		cout << "\ti: " << i;
		cout << "\tj: " << j;
		cout << "\tA: ";
		printVector(*A);
		do {
			j--;
		} while (A->at(j) > x);
		do {
			i++;
		} while (A->at(i) < x);
		if (i < j) {
			swap (A->at(i), A->at(j));
		} else {
			return j;
		}
	}
}

void hoareQuickSort_Print (vector<int> *A, int p, int r) {
	int q;
    if (p < r) {
        q = hoarePartition_Print (A, p, r);
        hoareQuickSort_Print (A, p, q-1);
        hoareQuickSort_Print (A, q+1, r);
    }
}

int main() {
	int ar[12] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
	vector<int> A;
	A.insert(A.begin(), ar, ar+12);
	
	printVector(A);
	hoareQuickSort_Print(&A, 0, A.size()-1);
	cout << endl;
	printVector(A);
}