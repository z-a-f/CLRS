typedef	std::vector<int>	MATRIX;

// Returns an empty matrix of size NxN
MATRIX matrixCreate (int N) {	// N is the edge of a square matrix
	MATRIX matrix;
	int size = pow(N, 2);
	
	matrix.resize(size);
	return matrix;	
}

// Sets "val" to matrix(row, col)
void matrixSet (MATRIX *matrix, int N, int row, int col, int val) {
	assert (row < N && col < N);
	// row and column indexing starts at 0
	// N is the edge of the square matrix
	int index = row * N + col;
	matrix->at(index) = val;
}

// Gets the value located at matrix(row, col)
int matrixGet (MATRIX matrix, int N, int row, int col) {
	int index = row * N + col;
	return matrix.at(index);
}

// Creates a zero matrix of size NxN
MATRIX matrixZero(int N) {
	MATRIX matrix = matrixCreate(N);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			matrixSet(&matrix, N, row, col, 0);
		}
	}
	return matrix;
}

// Creates an identity matrix of size NxN
MATRIX matrixEigen(int N) {
	MATRIX matrix = matrixCreate(N);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (row == col)
				matrixSet(&matrix, N, row, col, 1);
			else
				matrixSet(&matrix, N, row, col, 0);
		}
	}
	return matrix;
}

MATRIX matrixPopulate(int N) {
	MATRIX A = matrixCreate(N);
	int num;
	std::cout << "\nPlease enter the matrix row-by-row:\n";
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> num;
			matrixSet(&A, N, row, col, num);
		}
	}
	return A;
}

// Shows the values in a matrix
void matrixPrint (MATRIX matrix, int N) {	// N is the edge of a square matrix
	for (int row = 0; row < N; row++) {		// Row
		for (int col = 0; col < N; col++) {	// Col
			std::cout << matrixGet(matrix, N, row, col) << '\t';
		}
		std::cout << endl;
	}
}

// Matrix multiplication:
MATRIX squareMatrixMultiply (MATRIX A, MATRIX Bint N) {
	/*** BEGIN ALGORITHM 
	n = A.rows
	let C be a new nxn matrix
	for i = 1 to n
		for j = 1 to n
			c_ij = 0
			for k = 1 to n
				c_ij = c_ij + a_ik * b_kj
	return C
	END ALGORITHM ***/
	int val;
	MATRIX C = matrixZero(N);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			for (int k = 0; k < N; k++) {
				val = matrixGet(C, N, row, col) + matrixGet(A, N, row, k) * matrixGet(B, N, k, col);
				matrixSet(&C, N, row, col, val);
			}
		}
	}
	return C;
}

// Recursive matrix multiplication:
/*** BEGIN ALGORITHM
SQUARE-MATRIX-MULTIPLY-RECURSIVE(A, B)
	n = A.rows
	let C be a new nxn matrix
	if n == 1
		c_11 = a_11 * b_11
	else
		partition A, B, and C into quadrants
		C_11 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_11, B_11) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_12, B_21)
		C_12 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_11, B_12) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_12, B_22)
		C_21 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_21, B_11) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_22, B_21)
		C_22 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_21, B_12) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_22, B_22)
	merge C quadrants
	return C
END ALGORITHM ***/
