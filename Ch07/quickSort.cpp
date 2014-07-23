#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
// #include "./quickSort.hpp"



int partition(vector<int> *A, int p, int r) {
	/* Pseudo:
	PARTITION(A, p, r)
		x = A[r]
		i = p - 1
		for j = p to r - 1
			if A[j] <= x
				i = i + 1
				swap A[i] and A[j]
		swap A[i+1] and A[r]
		return i + 1
	*/
    int x = A->at(r);
    int i = p - 1;
    for (int j = p; j <= r-1; j++) {
        if (A->at(j) <= x) {
            i++;
            swap(A->at(i), A->at(j));
        }
    }
    swap(A->at(i+1), A->at(r));
    return i+1;
}

void quickSort(vector<int> *A, int p, int r) {
	/* Pseudo:
	QUICKSORT (A, p, r)
		if p < r
			q = PARTITION(A, p, r)
			QUICKSORT(A, p, q - 1)
			QUICKSORT(A, q + 1, r)
	*/
    int q;
    if (p < r) {
        q = partition (A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}


int main() {
    int N, num;
    vector<int> ar;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        ar.push_back(num);
    }
    
    printVector(ar);
    quickSort(&ar, 0, N-1);
    printVector(ar);
    
}


