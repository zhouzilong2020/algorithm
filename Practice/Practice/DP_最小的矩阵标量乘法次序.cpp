//
//  最小的矩阵标量乘法次序.cpp
//  Practice
//
//  Created by  周子龙 on 2020/5/8.
//  Copyright © 2020 周子龙. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


class Solution{
public:
    // p为各个矩阵的大小，n为矩阵个数，m、s作为结果分别保存矩阵i--j相乘时的最小乘法次数和乘法的顺序
    void matrixChain(vector<int> &p, int n){
        this->n = n;
        init();
        
        for(int i = 1; i <= n; i++)
            m[i][i] = 0;
        
        for(int len = 2; len <= n; len++)       //计算len个连续的矩阵相乘的最小标量乘法次序，这也是填表的顺序
            for(int l = 1; l <= n-len+1; l++){   //len个连续矩阵的左端起点
                int r = l+len-1;                //由起点l顺序往后len个矩阵的终点位置
                
                int t =m[l+1][r] + p[l-1]*p[l]*p[r];
                m[l][r] = t;
                
                for(int k = l+1; k < r; k++){      //k为分段位置
                    int tem = m[l][k] + m[k+1][r] + p[l-1]*p[k]*p[r];
                    if(tem < m[l][r]){
                        m[l][r] = tem;          //记录l...r需要的最小乘法次数
                        s[l][r] = k;            //记录分段点
                    }
                }
            }
    }

    void init(){
        if(!m && !s){
            delete  []m;
            delete  []s;
            m = new int*[n+1];
            s = new int*[n+1];
            for(int i = 0; i < n+1; i++){
                m[i] = new int[n+1];
                s[i] = new int[n+1];
                for(int j = 0; j < n+1; j++)
                    m[i][j] = s[i][j] = 0;
            }
        }
    }
    
    int getMin(int i, int j){
        return m[i][j];
    }
    
    void print(){
        for(int i = 1; i < n+1 ; i++){
            cout << endl;
            for(int j = 1; j < n+1 ; j++)
                cout  << setw(6) <<m[i][j] ;
        }
        cout << endl;

        
    }
    
private:
    int n;
    int **m = NULL;
    int **s = NULL;
};


void run(){
    vector<int> p ={30, 35, 15, 5, 10, 20, 25};
    int n = static_cast<int>(p.size()-1);
    Solution s;
    s.matrixChain(p, n);
    s.print();
    cout << s.getMin(1, n);
}
