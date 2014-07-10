#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    unsigned long long time[7];
    
    time[0] = 1*1000*1000;      // Time is given in microseconds
    time[1] = time[0] * 60;     // minute
    time[2] = time[1] * 60;     // hour
    time[3] = time[2] * 24;     // day
    time[4] = time[3] * 30;     // month
    time[5] = time[3] * 365;    // year
    time[6] = time[5] * 100;    // century
    
    
    // lg(n):
    cout << "lg(n)\t:\t";
    for (int i = 0; i < 7; i++)
        printf("%.2e\t", pow(2.0, (double)time[i]));
    cout << endl;
    cout << "lg(n) 2^:\t";
    for (int i = 0; i < 7; i++)
        printf("%.2e\t", (double)time[i]);
    cout << endl;
    
    // sqrt(n):
    cout << "sqrt(n)\t:\t";
    for (int i = 0; i < 7; i++)
        printf("%.2e\t", ((double)time[i]*time[i]));
    cout << endl;
    
    // n:
    cout << "n\t:\t";
    for (int i = 0; i < 7; i++)
        printf("%.2e\t", (double)time[i]);
    cout << endl;
    
    cout << "DAMN IT'S EASIER TO FILL UP THE TABLE BY HAND!!!\n";
}
