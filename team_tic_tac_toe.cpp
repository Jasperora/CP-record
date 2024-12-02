#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool equal(char a, char b, char c){
    if(a==b && b==c) return true;
    else return false;
}

bool threetypes(char a, char b, char c){
    if(a!=b && a!=c && b!=c) return true;
    else return false;
}


int main(){
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");

    char board[3][3];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            fin >> board[i][j];
        }
    }
    bool single_win[26] = {false}, double_win[26][26] = {false};

    // check row
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(equal(board[i][0], board[i][1], board[i][2]))
                single_win[int(board[i][0]-'A')] =  true;
            else if(!threetypes(board[i][0], board[i][1], board[i][2])){
                // two types
                if(board[i][0] != board[i][1])
                    double_win[int(board[i][0]-'A')][int(board[i][1]-'A')] = double_win[int(board[i][1]-'A')][int(board[i][0]-'A')] = true;
                else
                    double_win[int(board[i][0]-'A')][int(board[i][2]-'A')] = double_win[int(board[i][2]-'A')][int(board[i][0]-'A')] = true;
            }
                
        }
    }
    // check column
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(equal(board[0][i], board[1][i], board[2][i]))
                single_win[int(board[0][i]-'A')] =  true;
            else if(!threetypes(board[0][i], board[1][i], board[2][i])){
                // two types
                if(board[0][i] != board[1][i])
                    double_win[int(board[0][i]-'A')][int(board[1][i]-'A')] = double_win[int(board[1][i]-'A')][int(board[0][i]-'A')] = true;
                else
                    double_win[int(board[0][i]-'A')][int(board[2][i]-'A')] = double_win[int(board[2][i]-'A')][int(board[0][i]-'A')] = true;
            }
                
        }
    }
    // check diagonal
    if(equal(board[0][0], board[1][1], board[2][2])) single_win[int(board[0][0]-'A')] =  true;
    else if(!threetypes(board[0][0], board[1][1], board[2][2])){
        if(board[0][0] != board[1][1])
            double_win[int(board[0][0]-'A')][int(board[1][1]-'A')] = double_win[int(board[1][1]-'A')][int(board[0][0]-'A')] = true;
        else
            double_win[int(board[0][0]-'A')][int(board[2][2]-'A')] = double_win[int(board[2][2]-'A')][int(board[0][0]-'A')] = true;
    }
    if(equal(board[2][0], board[1][1], board[0][2])) single_win[int(board[2][0]-'A')] =  true;
    else if(!threetypes(board[2][0], board[1][1], board[0][2])){
        if(board[2][0] != board[1][1])
            double_win[int(board[2][0]-'A')][int(board[1][1]-'A')] = double_win[int(board[1][1]-'A')][int(board[2][0]-'A')] = true;
        else
            double_win[int(board[2][0]-'A')][int(board[0][2]-'A')] = double_win[int(board[0][2]-'A')][int(board[2][0]-'A')] = true;
    }

    int single_win_cnt = 0, double_win_cnt = 0;
    for(int i = 0; i < 26; ++i){
        single_win_cnt += single_win[i];
    }
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < 26; ++j){
            double_win_cnt += double_win[i][j];
        }
    }
    double_win_cnt /= 2;
    fout << single_win_cnt << '\n' << double_win_cnt;
}