#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    int N;
    fin >> N;
    char cows[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            fin >> cows[i][j];
        }
    }
    int cnt = 0;
    for(int i = N-1; i >= 0; --i){
        for(int j = N-1; j >= 0; --j){
            if(cows[i][j]=='1'){
                ++cnt;
                for(int k = 0; k <= i; ++k){
                    for(int l = 0; l <= j; ++l){
                        if(cows[k][l]=='1') cows[k][l] = '0';
                        else cows[k][l] = '1';
                    }
                }
            }
        }
    }
    fout << cnt;
}