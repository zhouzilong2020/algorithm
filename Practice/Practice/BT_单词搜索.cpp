//
//  单词搜索.cpp
//  Practice
//
//  Created by  周子龙 on 2020/5/5.
//  Copyright © 2020 周子龙. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isExist(vector<vector<char>>& b, string word); //给出一个字母宫，和代查找单词，返回是否存在，区分大小写
    
private:
    bool searchKthChar(int x, int y, int k);            //在棋盘中(x,y)处查询是否匹配第k个c字符
    inline bool isValide(int x, int y);                 //查询的位置(x，y)是否有效
    
    int ** checked;                                     //记录历史检查的信息，防止重复检查，1表示已经检查过该位置，0表示没有
    int dirc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};       //上下左右四个方向
    vector<vector<char>>* board;
    string word;
    int row;    //行数
    int col;    //列数
};

inline bool Solution::isValide(int x, int y){
    return -1 < x && x < row && -1 < y && y < col && checked[x][y] == 0;
}

bool Solution::isExist(vector<vector<char>>& b, string word){
    board = &b;                             //初始化信息
    row = static_cast<int>(b.size());
    col = static_cast<int>(b[0].size());
    this->word = word;
    checked = new int*[row];
    for(int i = 0; i < row; i++){           //初始化已检查数组
        checked[i] = new int[col];
        for(int j = 0; j < col; j++)
            checked[i][j] = 0;
    }

    for(int i = 0; i < row; i++)            //对每一个位置进行检查
        for(int j = 0; j < col; j++){
            checked[i][j] = 1;              //将当前位置标记为已经检查
            if(searchKthChar(i, j, 0))      //进入对当前位置的迭代
                return true;
            checked[i][j] = 0;              //撤销对该位置的检查信息
        }
    
    return false;                           //匹配失败，返回false
}

bool Solution::searchKthChar(int x, int y, int k){
    int new_x, new_y;
    
    if(board->at(x)[y] == word[k]){         //如果当前棋盘上的char和string中的第k个匹配
        if(k == word.size()-1)              //如果已经匹配到最后一位，则返回true
            return true;
        for(int i = 0; i < 4; i++){         //依次向当前位置的四周进行查找第k+1个位置的字母
            new_x = x+dirc[i][0];
            new_y = y+dirc[i][1];
            if(isValide(new_x, new_y)){     //如果该位置合法，则进入检查该位置
                checked[new_x][new_y] = 1;  //将该位置标记为已经检查，并进入对该位置的迭代搜索
                if(searchKthChar(new_x, new_y, k+1)) //如果搜索成功，则返回true
                    return true;
                checked[new_x][new_y] = 0;  //如果搜索不成功，则撤销本次检查信息
            }
        }
    }
    return false; //不匹配则返回false
}

void test(){
    vector<vector<char>> b1 = {  {'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";
    
    vector<vector<char>> b2 = {  {'A','A'},
                                 {'A','A'}};
    string word4 = "AAAAA";
    
    Solution s;
    
    cout << "test point1" << endl;
    if (s.isExist(b1, word1))
        printf("FOUND");
    else printf("NOT FOUND");
    cout << endl<< "test point2" << endl;
    if (s.isExist(b1, word2))
        printf("FOUND");
    else printf("NOT FOUND");
    cout <<  endl<<"test point3" << endl;
    if (s.isExist(b1, word3))
        printf("FOUND");
    else printf("NOT FOUND");
    cout <<  endl<<"test point4" << endl;
    if (s.isExist(b2, word4))
        printf("FOUND");
    else printf("NOT FOUND");
    getchar();
    
    
}
       
