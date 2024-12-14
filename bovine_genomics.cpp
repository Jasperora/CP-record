#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(){
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int N, M;
    fin >> N >> M;
    char gene[2*N][M];
    for(int i = 0; i < 2*N; ++i){
        for(int j = 0; j < M; ++j){
            fin >> gene[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < M; ++i){
        set<char> spot;
        set<char> plain;
        for(int j = 0; j < N; ++j){
            spot.insert(gene[j][i]);
        }
        for(int j = N; j < 2*N; ++j){
            plain.insert(gene[j][i]);
        }
        ++cnt;
        for(set<char>::iterator it = spot.begin(); it != spot.end(); ++it){
            if(plain.count(*it) == 1){
                --cnt;
                break;
            }
        }
    }
    fout << cnt;
}