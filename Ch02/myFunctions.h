void insertionSort(std::vector<int> *ar, int len) {
    int key;
    
    for (int j = 1, i; j < len; j++) {
        key = ar->at(j);
        // insert ar[j] into the stored sequency ar[0...j-1]:
        i = j - 1;
        while (i >= 0 && ar->at(i) > key) {     // Array starts from 0, so it's different from the book
            ar->at(i+1) = ar->at(i);
            i--;
        }
        ar->at(i+1) = key;
    }
}

void printVector(std::vector<int> ar) {
    for (std::vector<int>::iterator it = ar.begin(); it != ar.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

