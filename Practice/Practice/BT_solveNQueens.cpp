//
//  solveNQueens.cpp
//  Practice
//
//  Created by  周子龙 on 2020/4/18.
//  Copyright © 2020 周子龙. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



//优化：：可以直接将输出格式和棋盘的表示形式统一，省去转化时间
//N皇后问题
//输入：如N个皇后
//输出：在NxN棋盘上的所有可能的排法
class Solution {
public:
    vector<vector<string>> solveNQueens(int n){
        N = n;
        initBoard();
        search(0);
        return result;
    }
    
    void NQueen(int n){
        N = n;
        initBoard();
        search(0);
    }
    
    
private:
    char** board;
    int N;
    vector<vector<string>> result;
    const int DICT[5][2] = {{0,1}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}};//  检查是否冲突的方向，由于棋子生成的顺序，只需要向上检查，共五个方向回溯即可

    
    bool isValid(int x, int y);//    判断(x, y)是否合法，根据回溯法，棋盘上应该只有x个棋子，只需要检测前x-1行是否冲突即可
    void initBoard();//     初始化棋盘
    void printBoard();//    打印当前棋盘
    void search(int i);//   搜索第i行
    void save(){//          保存当前结果
        vector<string> newSolution;
        string line;
        for(int i = 0; i < N; i++){
            line.clear();
            for(int j = 0; j < N; j++)
                line += board[i][j];
            newSolution.push_back(line);
        }
        this->result.push_back(newSolution);
    }
};

void Solution::search(int i){
    if(i == N)
        return;
    for(int stack_col = 0; stack_col < N; stack_col++){
        if(isValid(i, stack_col)){
            board[i][stack_col] = 'Q';
            if(i == N-1){
//                printBoard();
                save();
            }
            search(i+1);
            board[i][stack_col] = '.';
        }
    }
    return;
}


void Solution::printBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("——————————————\n");
    
}


bool Solution::isValid(int x, int y){
    int LR_y, RL_y;
    int dia_flag = x - y;
    for(int i = 0; i < x; i++){
//            计算出两个对角线位置的y坐标，其中左上到右下的比较容易，右上到左下通过对称得出
        LR_y = i - dia_flag;
        RL_y = 2*y - LR_y;
//            前x-1行每一行最多有三个，对角线的元素可以用对称生成
        if(board[i][y] == 'Q')
//                同列上有棋子
            return false;
        if( (-1 < LR_y  && board[i][LR_y] == 'Q') || (RL_y < N && board[i][RL_y] == 'Q') )
//               检查对角线位置
            return false;
    }
    return true;
}

void Solution::initBoard(){
    board = new char*[N];
    for(int i = 0; i < N; i++)
        board[i] = new char[N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = '.';
}

// 1.生成全局棋盘
// 2.为第一行生成一个可能的位置，从左至右（保存在该层的栈里面）
// 3.递归调用，进入第二行，为第二行生成所有可能位置（保存在该层里面）
// ......
// 4.无发生成可能位置，则return


//int main(){
//    Solution S;
//    S.NQueen(5);
//    getchar();
//}
