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
    for(int i = 0; i < M-2; ++i){
        for(int j = i+1; j < M-1; ++j){
            for(int k = j+1; k < M; ++k){
                set<string> spotty, plain;
                string s;
                for(int l = 0; l < N; ++l){
                    s = "";
                    s.push_back(gene[l][i]);
                    s.push_back(gene[l][j]);
                    s.push_back(gene[l][k]);
                    spotty.insert(s);
                }
                for(int l = N; l < 2*N; ++l){
                    s = "";
                    s.push_back(gene[l][i]);
                    s.push_back(gene[l][j]);
                    s.push_back(gene[l][k]);
                    plain.insert(s);
                }
                bool is_pattern = true;
                for(auto& sp : spotty){
                    is_pattern &= !plain.count(sp);
                }
                cnt += is_pattern;
            }
        }
    }
    fout << cnt;
}