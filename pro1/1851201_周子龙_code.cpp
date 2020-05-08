//
//  main.cpp
//  Pro1
//
//  Created by  周子龙 on 2020/3/14.
//  Copyright © 2020 周子龙. All rights reserved.
//

#include <iostream>

struct pos{
    int i;
    int j;
    pos(){
        i = -1; j = -1;
    }
};


//Implements of nonrecursive improved binary search
//Input: An array A[0…n-1] sorted in ascending order and a search key x.
//Output: If x is not in the array, return the biggest index i and the
//      smallest index j, which A[i] < x < A[j]. If x is in the array,
//      the return value i, j will be of the same value.
//      In extreme cases where there is no bigger/smaller key value than x, algorithm         will return -1.
template<class T>
void ImprovedBinarySearch(T *A, int n, T x, pos &p){
    int i = 0, j = n-1;
    int mid;
    //normal binary search process
    while(i < j){//i will always point to the biggest index which A[i] >= x
        mid = (i+j)/2;
        if(A[mid] < x)
        { i = mid+1;}
        else if(A[mid] > x)
        { j = mid-1;}
        else { i = j = mid; };
    }
    if(A[i] < x){//in case x is bigger than the biggest key value of the array
        p.i = j; p.j = -1;
    }
    else if(A[i] == x){
        p.i = p.j = i;
    }
    else{
        p.j = i; p.i = i-1;
    }
    printf("input:%-5d, A[i] = %-5d, A[j] = %-5d\n", x, (p.i < 0) ? -1 : A[p.i], (p.j < 0) ? -1 : A[p.j]);
}

int main(int argc, const char * argv[]) {
    int A[] = {2,4,6,14,51,66,78,345,1234,6783};
    pos p;
    
    //x does not reside in array A
    ImprovedBinarySearch<int>(A, 10, 70, p);
    ImprovedBinarySearch<int>(A, 10, 60, p);
    ImprovedBinarySearch<int>(A, 10, 1, p);     //extream case
    ImprovedBinarySearch<int>(A, 10, 10000, p); //extream case
    
    //successful search
    ImprovedBinarySearch<int>(A, 10, 51, p);
}
