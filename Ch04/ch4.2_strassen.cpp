#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#include "matrixFunctions.h"

int main() {
	int N;	// N is the edge of a square matrix
	cout << "Enter the number of rows/columns of a square matrix: ";
	cin >> N;
	
	MATRIX A = matrixPopulate(N);
	MATRIX B = matrixPopulate(N);
	
	MATRIX C = squareMatrixMultiply(A, B, N);
	
	cout << endl;
	matrixPrint(C, N);
}