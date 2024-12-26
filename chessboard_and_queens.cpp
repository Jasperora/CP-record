#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt = 0;
void count(int queen_num, const char board[8][8], const vector<pair<int, int> > available){
    if(queen_num==8) {
        ++cnt;
        // for(int i = 0; i < 8; ++i){
        //     for(int j = 0; j < 8; ++j){
        //         cout << board[i][j];
        //     }
        //     cout << '\n';
        // }
        // cout << "===========\n";
        return;
    }
    else{
        for(int i = 0; i < available.size(); ++i){
            if(available[i].first==queen_num){
                char tmp[8][8];
                for(int j = 0; j < 8; ++j){
                    for(int k = 0; k < 8; ++k){
                        tmp[j][k] = board[j][k];
                    }
                }
                tmp[available[i].first][available[i].second] = 'Q';
                vector<pair<int, int> > left;
                for(int j = 0; j < available.size(); ++j){
                    if(available[j].first!=available[i].first && available[j].second!=available[i].second && abs(available[j].first-available[i].first)!=abs(available[j].second-available[i].second))
                        left.push_back(make_pair(available[j].first, available[j].second));
                }

                count(queen_num+1, tmp, left);
            }
        }
    }
}
int main(){
    char board[8][8];
    vector<pair<int, int> > available;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            cin >> board[i][j];
            if(board[i][j]=='.') available.push_back(make_pair(i, j));
        }
    }
    count(0, board, available);
    cout << cnt;
}