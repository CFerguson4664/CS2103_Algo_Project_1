// Christopher Ferguson
// 9/28/22
// Quick Sort Implementation

#include <iostream>
#include "Address.h"
#include "Sorts.h"

using namespace std;


void swap(Address **A, int x, int y)
{
    Address *temp;
    temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int Partition(Address **A, int p, int r) {
    Address *x = A[r];
    int i = p-1;
    
    for(int j = p; j < r; j++) {
        if(LessThan(A[j], x)) {
            i += 1;
            swap(A,i,j);
        }
    }
    swap(A,i+1,r);
    return (i + 1);
}

void Quick_Sort(Address **A, int p, int r) {
    if(p < r) {
        int q = Partition(A,p,r);
        Quick_Sort(A, p, (q-1));
        Quick_Sort(A, (q+1), r);
    }
}



// int A[6] = {8,5,2,4,-3,68};

// int main()
// {
//     int N = sizeof(A) / sizeof(A[0]);
    
//     Quick_Sort(A,0,N-1);
    
//     for(int i = 0; i < N; i++) {
//         cout << A[i] << " ";
//     }
//     cout<<endl;

//     return 0;
// }
