int partition(vector<int> *A, int p, int r) {
	/* Pseudo:
	PARTITION(A, p, r)
		x = A[r]
		i = p - 1
		for j = p to r - 1
			if A[j] <= x
				i = i + 1
				swap A[i] and A[j]
		swap A[i+1] and A[r]
		return i + 1
	*/
    int x = A->at(r);
    int i = p - 1;
    for (int j = p; j <= r-1; j++) {
        if (A->at(j) <= x) {
            i++;
            swap(A->at(i), A->at(j));
        }
    }
    swap(A->at(i+1), A->at(r));
    return i+1;
}

void quickSort(vector<int> *A, int p, int r) {
	/* Pseudo:
	QUICKSORT (A, p, r)
		if p < r
			q = PARTITION(A, p, r)
			QUICKSORT(A, p, q - 1)
			QUICKSORT(A, q + 1, r)
	*/
    int q;
    if (p < r) {
        q = partition (A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////

int random(int p, int r) {
	int i = rand() % (r - p + 1) + p;
	return i;
}

int randomizedPartition (vector<int> *A, int p, int r) {
	int i = random(p, r);
	swap(A[i], A[r]);
	return partition(A, p, r);
}

void randomizedQuickSort(vector<int> *A, int p, int r) {
	int q;
    if (p < r) {
        q = randomizedPartition (A, p, r);
        randomizedQuickSort(A, p, q-1);
        randomizedQuickSort(A, q+1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////

int hoarePartition(vector<int> *A, int p, int r) {
	int x = A->at(p);
	int i = p - 1;
	int j = r + 1;
	while (true) {
		do {
			j--;
		} while (A->at(j) > x);
		do {
			i++;
		} while (A->at(i) < x);
		if (i < j) {
			swap (A->at(i), A->at(j));
		} else {
			return j;
		}
	}
}

void hoareQuickSort (vector<int> *A, int p, int r) {
	int q;
    if (p < r) {
        q = hoarePartition (A, p, r);
        hoareQuickSort(A, p, q-1);
        hoareQuickSort(A, q+1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////

void tailRecursiveQuickSort(vector<int> *A, int p, int r) {
	int q;
	while (p < r) {
		q = partition(A, p, r);
		tailRecursiveQuickSort(A, p, q-1);
		p = q + 1;
	}
}

////////////////////////////////////////////////////////////////////////////////////////

int medianOf3(int a, int b, int c) {
	if ((a <= b && a > c) || (a > b && a <= c)) {	// a is median
		return a;		
	} else if ((b <= a && b > c) || (b > a && b <= c)) {	// b is median
		return b;		
	} else if ((c <= b && c > a) || (c > b && c <= a)) {	// c is median
		return c;		
	} else {
		return a;
	}
}

int medianOf3Vector (vector<int> A, int p, int r) {
	int len = r - p + 1;
	int x1, x2, x3;
	int n3 = pow(len, 3) - 1;
	// Choose 3 numbers randomly (out of n^3):
	if (len > 3) {
		x1 = random(0, n3) % len + p;
		x2 = random(0, n3) % len + p;
		x3 = random(0, n3) % len + p;
	} else {
		return A.at(0);	// Simple case
	}
	cout << A.at(x1) << ' ' << A.at(x2) << ' ' << A.at(x3) << endl;
	return medianOf3 (A.at(x1), A.at(x2), A.at(x3));
}

int partitionMo3(vector<int> *A, int p, int r) {
    int x = medianOf3Vector(*A, p, r);
    cout << A->at(p) << ' ' << A->at(r) << endl;
    cout << x << endl;
    int i = p - 1;
    for (int j = p; j <= r-1; j++) {
        if (A->at(j) <= x) {
            i++;
            swap(A->at(i), A->at(j));
        }
    }
    swap(A->at(i+1), A->at(r));
    return i+1;
}

void quickSortMo3 (vector<int> *A, int p, int r) {
    int q;
    if (p < r) {
        q = partitionMo3 (A, p, r);
        quickSortMo3(A, p, q-1);
        quickSortMo3(A, q+1, r);
    }
}
