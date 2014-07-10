#ifndef __MY__INCLUDES__H
#include "myIncludes.h"
#endif

#ifndef __MY__OTHER__FUNCTIONS__H
#include "otherFunctions.h"
#endif
////////////////////////////////////////////////////////////////////////////////////////


int linSearch (std::vector<int> ar, int num) { // p2.1-3 for Loop invariant
	int i = 0;
	
	// Check initialization:
	printVector(ar);
	std::cout << num << ' ' << i  << std::endl;
	
	for (std::vector<int>::iterator it = ar.begin(); it != ar.end(); ++it) {
		// Check maintenance by checking that the number is not in the already checked array:
		std::cout << i << ". Number: " << num << " Array: ";
		for (int j = 0; j < i; j++) {
			std::cout << ar[j] << ' ';
		}
		std::cout << std::endl;
		
		if (num == *it) {
			std::cout << "Termination OK" << std::endl;
			return i;
		}
		i++;
	}
	std::cout << "Termination OK" << std::endl;
	return -1;
}
