#include <iostream>
#include <set>
#include <cassert>
#include <stdio.h>

using namespace std;

/* Approach:
 *	Create a 64-bit iterator "it". "it" will have a form: 0000...0011...1111, where the position of "1"
 *	represents the position in the array (set). Another variable "itShift" represents a shifting iterator
 *	where for every "it", "itShift" will iterate through the bits, and show ar[i] if the i-th bit is "1".
 *	After that "it" is decremented, and the operation repeats:
 *
 *	
 */

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