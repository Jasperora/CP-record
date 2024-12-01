#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");

    int M, N, K;
    fin >> M >> N >> K;
    char signal[M][N];
    char c;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            fin >> c;
            signal[i][j] = c;
        }
    }
    for(int i = 0; i < M; ++i){
        for(int k = 0; k < K; ++k){
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < K; ++k){
                    fout << signal[i][j];
                }
                fout << '\n';
        }
    }

}