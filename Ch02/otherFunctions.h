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


////////////////////////////////////////////////////////////////////////////////////////
#endif