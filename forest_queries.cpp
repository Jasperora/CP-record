#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    char c;
    bool square[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> c;
            if(c=='*') square[i][j] = true;
            else square[i][j] = false;
        }
    }
    int ps[n+1][n+1];
    for(int i = 0; i < n+1; ++i){
        for(int j = 0; j < n+1; ++j){
            if(i==0||j==0)
                ps[i][j] = 0;
            else
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + square[i-1][j-1];
        }
    }
    int y1, x1, y2, x2;
    for(int i = 0; i < x; ++i){
        cin >> y1 >> x1 >> y2 >> x2;
        if(y1==y2&&x1==x2) cout << square[y1-1][x1-1] << '\n';
        else if(y1>=y2&&x1>=x2){
            cout << ps[y1][x1] - ps[y1][x2-1] - ps[y2-1][x1] + ps[y2-1][x2-1] << '\n';
        }else{
            cout << ps[y2][x2] - ps[y2][x1-1] - ps[y1-1][x2] + ps[y1-1][x1-1] << '\n';
        }
    }
}