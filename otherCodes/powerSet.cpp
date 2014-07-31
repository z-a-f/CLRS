#include <iostream>
#include <set>
#include <cassert>
#include <stdio.h>

using namespace std;


int main() {
	cout << "Please, enter N: ";
	int N;
	cin >> N;
	// Assume that the maximum number of elements is < 64
	// For larger number of elements the possible combinations will exceed any reasonable memory constraints
	assert (N <= 64);
	// populate the initial array:
	int ar[N];
	for (int i = 1; i <= N; i++) {
		ar[i-1] = i;
	}
	
	unsigned long long it = (1 << N) - 1;	// The LSB represents the first element, LSB+1 -> second element, etc
	// printf("%llx\n", it);
	unsigned long long itShift;
	while (it) {
		int i = 0;
		cout << "{ ";
		for (itShift = it; itShift > 0; itShift = itShift >> 1) {
			if (itShift % 2 != 0) {
				cout << ar[i] << ' ';
			}
			i++;
		}
		cout << '}' << endl;
		it--;
	}
}