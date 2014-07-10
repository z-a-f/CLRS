#include "myIncludes.h"
#include "myFunctions.h"

using namespace std;

struct boolTuple {
	bool MSB;
	bool LSB;
};

boolTuple halfAdder (bool A, bool B) {
	boolTuple C;
	
	C.MSB = A & B;
	C.LSB = A ^ B;
	return C;
}

boolTuple fullAdder (bool A, bool B, bool C) {
	boolTuple SUM;
	
	SUM.LSB = A ^ B ^ C;
	SUM.MSB = (A & B) | (A & C) | (B & C);
	
	return SUM;
}
	
int main () {
	vector<bool> A;
	vector<bool> B;
	int n;
	bool C[n+1];
	bool num;
	
	cout << "Enter bitlength: ";
	cin >> n;
	cout << "Enter number A: ";
	for (int i = 0; i < n; i++) {
		cin >> num;
		A.push_back(num);
	}
	
	cout << "Enter number B: ";
	for (int i = 0; i < n; i++) {
		cin >> num;
		B.push_back(num);
	}
	
	boolTuple carry;
	carry = halfAdder (A[n-1], B[n-1]);
	C[n] = carry.LSB;
	for (int i = n-2; i >= 0; i--) {
		carry = fullAdder (A[i], B[i], carry.MSB);
		C[i+1] = carry.LSB;
	}
	C[0] = carry.MSB;
	
	
	for (int i = 0; i <= n; i++ ) {
		cout << C[i] << ' ';
	}
	cout << endl;

}