#ifndef __FUNCTIONS__
#define __FUNCTIONS__


#include "myIncludes.h"

void printVector(vector<int> ar) {
    for (vector<int>::iterator it = ar.begin(); it != ar.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

int getVector (vector<int> *ar) {
    int N;
    cin >> N;
    int num;
    ar->erase(ar->begin(), ar->end());
    for (int i = 0; i < N; i++) {
        cin >> num;
        ar->push_back(num);
    }
    return N;
}

int getVectorChange (vector<int> *ar) {
    int N;
    cin >> N;
    int num1, num2;
    ar->erase(ar->begin(), ar->end());
    cin >> num1;
    for (int i = 1; i < N; i++) {
        cin >> num2;
        ar->push_back(num2-num1);
        num1 = num2;
    }
    return N - 1;
}


#endif