#include <iostream>
#include <fstream>
using namespace std;


int main(){
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    int K, N;
    fin >> K >> N;
    int order[K][N], rank[K][N];
    for(int i = 0; i < K; ++i){
        for(int j = 0; j < N; ++j){
            fin >> order[i][j];
        }
    }
    for(int i = 0; i < K; ++i){
        for(int j = 0; j < N; ++j){
            rank[i][order[i][j]-1] = j;
        }
    }

    int cnt = 0;
    int tmp1, tmp2;
    bool bigger, is_consistent;
    for(int i = 0; i < N - 1; ++i){
        for(int j = i + 1; j < N; ++j){
            is_consistent = true;
            for(int k = 0; k < K; ++k){
                if(rank[k][i] > rank[k][j]){
                    if(k==0) bigger = true;
                    if(bigger==false){
                        is_consistent = false;
                        break;
                    }
                }else{
                    if(k==0) bigger = false;
                    if(bigger==true){
                        is_consistent = false;
                        break;
                    }
                }
            }
            cnt += is_consistent;
        }
    }
    fout << cnt;
}