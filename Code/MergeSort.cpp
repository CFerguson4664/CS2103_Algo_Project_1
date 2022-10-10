// Christopher Ferguson
// 9/22/22
// Merge Sort Implementation

#include <iostream>
#include "Address.h"
#include "Sorts.h"

using namespace std;

void Merge_Proc(Address **A, int p, int q, int r) {
    int n1 = (q-p) + 1;
    int n2 = r-q;
    
    Address *L[n1 + 1];
    Address *R[n2 + 1];

    for(int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    
    for(int i = 0; i < n2; i++) {
        R[i] = A[q + i + 1];
    }
    
    L[n1] = new Address( // This is a very large address
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    );

    R[n2] = new Address( // This is a very large address
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    );
    
    int i = 0;
    int j = 0;
    for(int k = p; k < r + 1; k++) {
        if(LessThan(L[i],R[j]) || EqualTo(L[i],R[j])) {
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
    }
}

void Merge_Sort(Address **A, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        Merge_Sort(A,p,q);
        Merge_Sort(A,q+1,r);
        Merge_Proc(A,p,q,r);
    }
}
