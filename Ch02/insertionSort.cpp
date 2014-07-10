#include <vector>
#include <iostream>

#include "myFunctions.h" 

using namespace std;

int main () {
    int len, num;
    cin >> len;
    
    vector <int> ar;
    
    for (int i = 0; i < len; i++) {
        cin >> num;
        ar.push_back(num);
    }
    
    printVector(ar);
    insertionSort(&ar, len);
    printVector(ar);
    
}
