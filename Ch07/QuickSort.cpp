#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printVector (vector<int> A) {
  for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(vector<int> *A, int p, int r) {
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


