void countingSort (vector<int> *A, int k) {
  // Create temporary storage of size A:
  vector<int> B = *A;
  
  // The range for valid values is [0..k] inclusive
  int C[k+1];		// count array for values [0..k]
  
  // initialize the count:
  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }
  
  // populate the count:
  for (vector<int>::iterator it = B.begin(); it != B.end(); ++it) {
    C[*it]++;
  }

  // Create a running sum for the count:
  for (int i = 1; i <= k; i++) {
    C[i] += C[i-1];
  }

  // Sort the arrays:
  for (vector<int>::reverse_iterator it = B.rbegin(); it != B.rend(); ++it) {
    A->at(C[*it]-1) = *it;
    C[*it]--;
  }
}

void countingSort_D (vector<int> *A, int d) {
  const int k = 9;
  int num;
  // Create temporary storage of size A:
  vector<int> B = *A;
  
  // The range for valid values is [0..k] inclusive
  int C[k+1];		// count array for values [0..k]
  
  // initialize the count:
  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }
  
  // populate the count:
  for (vector<int>::iterator it = B.begin(); it != B.end(); ++it) {
    num = (*it % int (pow(10, d))) / int (pow(10, d-1));
    C[num]++;
  }

  // Create a running sum for the count:
  for (int i = 1; i <= k; i++) {
    C[i] += C[i-1];
  }

  // Sort the arrays:
  for (vector<int>::reverse_iterator it = B.rbegin(); it != B.rend(); ++it) {
    num = (*it % int (pow(10, d))) / int (pow(10, d-1));
    A->at(C[num]-1) = *it;
    C[num]--;
  }
}

//////////////////////////////////////////////////////////

void radixSort (vector<int> *A, int d) {
  // d is the maximum order. For example d=5 means the maximum sorting will
  // be up until 5 digits. d = 1 is just sorting the ones...
  for (int i = 1; i <= d; i++){
    countingSort_D(A, i);
  }
}

//////////////////////////////////////////////////////////

void bucketSort (vector<float> *A, int n) {
  // Create buckets:
  vector<float> B[n];
  
  // Push back the elements into buckets:
  for (int i = 0; i < n; i++) {
    int index = floor(n*A->at(i));
    B[index].push_back(A->at(i));
  }

  // Sort buckets:
  for (int i = 0; i < n; i++ ) {
    sort(B[i].begin(), B[i].end());
  }

  // Get back the arrays:
  A->clear();
  for (int i = 0; i < n; i++) {
    //for (vector<float>::iterator it = B[i].begin(); it != B[i].end(); ++it){
    A->insert(A->end(), B[i].begin(), B[i].end());
    //}
  }
}
