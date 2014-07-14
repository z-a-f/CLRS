#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> matrixCreate (int N) {
	vector <int> matrix;
	int size = N*N;
	
	matrix.resize(size);
	return matrix;	
}

void matrixSet (vector<int> *matrix, int size, int row, int col, int val) {
	int index = col + row*size;
	matrix->at(index) = val;
}

int matrixGet (vector<int> matrix, int size, int row, int col) {
	int index = col + row*size;
	return (matrix[index]);
}

vector<int> squareMatrixMultiply (vector<int> A, vector<int> B, int size) {
	int a, b, c, n;
	n = sqrt(size);
	vector<int> C = matrixCreate(size);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixSet(&C, size, i, j, 0);
			for (int k = 0; k < n; k++) {
				a = matrixGet(A, size, i, j);
				b = matrixGet(B, size, i, j);
				c = matrixGet(C, size, i, j);
				matrixSet(&C, size, i, j, a*b+c);
			}
		}
	}
	return C;
}

int main() {
	int N;
	cin >> N;
		
	vector<int> A = matrixCreate(N);
	vector<int> B = matrixCreate(N);
	vector<int> C = matrixCreate(N);
	
	int num;
	for (int i = 0; i < 4; i++) {
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < 4; i++) {
		cin >> num;
		B.push_back(num);
	}
	
	C = squareMatrixMultiply(A, B, N*N);
	
	for (vector<int>::iterator it = C.begin(); it != C.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	
	
}