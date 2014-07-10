
#include "myIncludes.h"
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
    
    mergeSort(&ar, 0, len-1);
    printVector(ar);
}