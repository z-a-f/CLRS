#include <cmath>
#include <iostream>

using namespace std;

double alg1 (int n) {
    return 100*n*n;
}

double alg2 (int n) {
    return pow(2.0,n);
}

int main() {
    int n = 1;
    while (alg1(n) > alg2(n))
        n++;
         
    cout << n << endl;
}
