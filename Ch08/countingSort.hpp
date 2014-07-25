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
