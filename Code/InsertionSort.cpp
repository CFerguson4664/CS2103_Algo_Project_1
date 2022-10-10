// Christopher Ferguson
// 9/22/22
// Insertion Sort Implementation

#include <iostream>
#include "Address.h"
#include "Sorts.h"

using namespace std;

void Insertion_Sort(Address **A, int n){
    for (int j = 1; j <  n; j++) {
        Address *key = A[j];
        int i = j-1;
        
        while(i >= 0 && GreaterThan(A[i], key)) {
            A[i+1] = A[i];
            i = i-1;
        }
        
        A[i+1] = key;
    }
}
