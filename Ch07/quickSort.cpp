#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"
#include "./quickSort.hpp"

int main() {
    int N, num;
    vector<int> ar;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        ar.push_back(num);
    }
    
    printVector(ar);
    randomizedQuickSort(&ar, 0, N-1);
    printVector(ar);
    
}


