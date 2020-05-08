//
//  main.cpp
//  Practice
//
//  Created by  周子龙 on 2020/3/10.
//  Copyright © 2020 周子龙. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



/**
 *1-1 Computing gcd(m,n)
 **/
int gcd_Euclid(int m, int n){
    int mod;
    if(m < 0 || n < 0)
        return -1;
    if(n > m){
        int tem;
        tem = m;
        m = n;
        n = tem;
    }
    while(n != 0){
        mod = m%n;
        m = n;
        n = mod;
    }
    return m;
}

int gcd_consecutive(int m, int n){
    int i = 0;
    if(m < 0|| n <0)
        return -1;
    if(m > n){
        int tem;
        tem = m;
        m = n;
        n = tem;
    }
    
    for(i = m; i > 0; i--){
        if(m % i == 0 && n % i == 0)
            break;
    }
    return i;
}

/**
 *1-2 find the binary representation of a positive decimal integre
 **/
string converIntoBinary(double i, int p){//conver decimal integer into bineray code in p digit percision
    string result;
    vector<char> stack;
    string tem;
    int integer = static_cast<int>(i/1);
    double decimal = static_cast<double>(i - integer);
    
    if(p < 0 || i <= 0){//invalid input
        return "Invalid input!";
    }
    
    if(integer == 0){ //if there is no integer part
        result.append("0");
    }
    else{
        while(integer != 0){   //for the integer part
            if (integer % 2 == 1) {stack.push_back('1'); }
            else {stack.push_back('0');}
            integer/=2;
        }
        while(!stack.empty()){
            tem = stack.back();
            result.append(tem);
            stack.pop_back();
        }
    }
    
    result.append("."); //add decimal point
    
    if(decimal == 0){//if there is no decimal part
        while(p > 0) {result.append("0"); p--;}
    }
    
    while(decimal > 0 && p > 0){     //for the decimal part
        decimal*=2;
        if(decimal > 1){result.append("1"); decimal-=1;}
        else{result.append("0");}
        p--;
    }
    return result;
}



/**
 *1-3.unique Element
 **
 before sort:
    worst case:     o(n^2)
    best case:      o(1)
    average case:   o(n^2)
 after sort:
    worst case:     o(nlogn)
    best case:      o(1)
    average case:   o(nlogn)
 **/
bool uniqueElement(int *A, int n){//input an aaray whose length is n
    if(A == NULL || n <= 0){
        cout << "Invalid input!";
        return false;
    }
    
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(A[i] == A[j]){
                return false;
            }
    return true;
}

bool sort_uniqueElement(int *A, int n){//input an aaray whose length is n
    if(A == NULL || n <= 0){
        cout << "Invalid input!";
        return false;
    }
    
    sort(A, A+n-1);
    
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(A[i] == A[j]){
                return false;
            }
    return true;
}
