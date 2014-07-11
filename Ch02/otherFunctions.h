#ifndef __MY__INCLUDES__H
#include "myIncludes.h"
#endif

#if !defined ( __MY__OTHER__FUNCTIONS__H )
#define __MY__OTHER__FUNCTIONS__H
////////////////////////////////////////////////////////////////////////////////////////

void printVector(std::vector<int> ar) {
    for (std::vector<int>::iterator it = ar.begin(); it != ar.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}



void swap (int *A, int *B) {
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}


long long hornerRule (int x, std::vector<int>coeffs, int len) {
	/*******************************************
	* This function computes a polynomial using
	* Horner's Rule. A polynomial of the form
	* P(x) = sum(a[k]*x^k, k = {0, n})
	********************************************/
	long long y = 0;
	for (int i = len-1, i >= 0; i--)
		y = coeffs.at(i) + x * y;
		
	return y;
}

////////////////////////////////////////////////////////////////////////////////////////
#endif