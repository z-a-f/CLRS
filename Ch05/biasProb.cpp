#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

int main () {
	int p;

	srand(time(NULL));
	p = (rand() % 1000);	// Bias probability
	
	int num;
	int ones = 0;
	int zeros = 0;
	double k = 1000000.0;
	double K = k;
	
	// Before removing the bias
	do {
		num = rand() % 1000;
		if (num <= p)
			zeros++;
		else
			ones++;
	} while (k--);
	
	cout << "Before bias removal:\t";
	cout << "p: " << (double)p/1000.0 << " zeros: " << zeros/K << " ones: " << ones/K << endl;
	
	// After removing the bias (alternate)
	ones = 0;
	zeros = 0;
	k = K;
	int alt = 0;
	
	do {
		num = rand()%1000;
		if (alt) {
			alt = 0;
			if (num <= p)
				zeros++;
			else
				ones++;
		} else {
			alt = 1;
			if (num <= p)
				ones++;
			else
				zeros++;
		}
	} while (k--);
	
	cout << "After bias removal:\t";
	cout << "p: " << (double)p/1000.0 << " zeros: " << zeros/K << " ones: " << ones/K << endl;
}	
