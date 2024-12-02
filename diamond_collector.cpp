#include <iostream>
#include <fstream>
using namespace std;


int main(){
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N, K;
    fin >> N >> K;
    int size[N];
    for(int i = 0; i < N; ++i){
        fin >> size[i];
    }
    int max = 0, tmp;
    for(int i = 0; i < 10000; ++i){
        tmp = 0;
        for(int j = 0; j < N; ++j){
            if(size[j] >= i && size[j] <= i + K){
                ++tmp;
            }
        }
        if(tmp > max) max = tmp;
    }
    fout << max;

}