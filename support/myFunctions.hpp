#ifndef __MY_FUNCTIONS__
#define __MY_FUNCTIONS__

#define	printVector(A)	vectorPrint(A)

void vectorPrint (vector<int> A) {
  for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


#endif