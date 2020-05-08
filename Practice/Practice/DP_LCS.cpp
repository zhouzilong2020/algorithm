//
//  LCS.cpp
//  Practice
//
//  Created by  周子龙 on 2020/5/8.
//  Copyright © 2020 周子龙. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    Solution(){
        len = NULL;
        len1 = 0;
        len2 = 0;
    }
    int longestCommonSubsequence(string text1, string text2);
    void init();
    void print(int **p);
private:
    int **len;//动态规划填表 len[len1][len2]
    int **pos;//填表同时记录选择的字母
    int len1; //字符串1的长度
    int len2; //字符串2的长度
};

void Solution::init(){
    if(len)                 //初始动态规划表
        delete *len;
    len = new int*[len1+1];
    pos = new int*[len1+1];
    
    for(int i = 0; i < len1+1; i++){
        len[i] = new int[len2+1];
        pos[i] = new int[len2+1];
        for(int j = 0; j < len2+1; j++)
            {len[i][j] = 0; pos[i][j] = 0;}
    }
}

void Solution::print(int **p){
    for(int i = 0; i < len1+1; i++){
        for(int j = 0;j < len2+1; j++){
            printf("%-5d", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Solution::longestCommonSubsequence(string text1, string text2){
    /*初始化*/
    len1 = static_cast<int>(text1.length());
    len2 = static_cast<int>(text2.length());
    init();
    
    
    /*动态规划算法开始*/
    for(int i = 1; i < len1+1; i++) //i从1开始，两个字符串的下标和实际位置有区别
        for(int j = 1; j < len2+1; j++){
            if(text1[i-1] == text2[j-1]){
                len[i][j] = 1 + len[i-1][j-1];
                pos[i][j] = 0;
            }
            else if(len[i][j-1] > len[i-1][j]){
                len[i][j] = len[i][j-1];
                pos[i][j] = -1;
            }
            
            else{
                len[i][j] = len[i-1][j];
                 pos[i][j] = 1;
            }
        }
    
    return len[len1][len2];
}

void run(){
    Solution s;
    int num = s.longestCommonSubsequence("AABCD", "ABD");
    printf("%d", num);
}
