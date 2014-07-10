#include <cmath>
#include <iostream>

using namespace std;

double insertionSortRunTime(int n) {
    return 8*n*n;
}

double mergeSortRunTime (int n) {
    return 64*n*log2(n);
}

int main() {
    int n = 2;
    while (insertionSortRunTime(n) < mergeSortRunTime(n))
        n++;
        
    cout << n << endl;
}
