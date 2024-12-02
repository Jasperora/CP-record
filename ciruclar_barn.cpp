#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int n;
    fin >> n;
    int r[2*n];
    for(int i = 0; i < n; ++i){
        fin >> r[i];
        r[i+n] = r[i];
    }
    int min = 2147483647, dist_cnt;
    for(int i = 0; i < n; ++i){
        dist_cnt = 0;
        for(int j = 0; j < n-1; ++j){
            dist_cnt += (j+1) * r[i+j+1];
        }
        if(dist_cnt < min) min = dist_cnt;
    }
    fout << min;
}