#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printVector (vector<int> A) {
  for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}

vector<int> countingSort(vector<int> A, int k) {
    vector<int> B = A;  // Just initialize to anything for now;
    int C[k+1];
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
        C[*it]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    for (vector<int>::iterator it = A.end(); it != A.begin(); --it) {
        B.at(C[*it]) = *it;
        C[*it] -= 1;
    }
    
    return B;
}

int main() {
    vector<int> A;
    int N, k, num;
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> num;
        A.push_back(num);
    }
    printVector(A);
    A = countingSort(A, k);
    printVector(A);
}
