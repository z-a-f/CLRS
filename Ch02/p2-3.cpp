#include "myIncludes.h"
#include "myFunctions.h"

using namespace std;

int main() {
	int len, num;
    cin >> len;
    
    vector <int> coeffs;
    cout << "Please enter the coefficients: ";
    for (int i = 0; i < len; i++) {
        cin >> num;
        coeffs.push_back(num);
    }
	cout << "Please, enter the x: ";
	int x;
	cin >> x;   
	
	cout << "The result is: " << hornerRule(x, ar, len) << endl;
}