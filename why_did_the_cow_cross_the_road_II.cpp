#include <iostream>
#include <fstream>
using namespace std;

bool overlap(int i1, int i2, int j1, int j2){
    if(i1 < j1  && j1 < i2 && i2 < j2) return true;
    if(j1 < i1 && i1 < j2 && j2 < i2) return true;
    return false;
}

int main(){
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    char points[52];
    for(int i = 0; i < 52; ++i) fin >> points[i];

    int cnt = 0;
    for(int i = 0; i < 25; ++i){
        for(int j = i+1; j < 26; ++j){
            int i1, i2, j1, j2;
            bool has_i1 = false, has_j1 = false;
            for(int k = 0; k < 52; ++k){
                if(points[k]==char('A'+i) && !has_i1){
                    i1 = k;
                    has_i1 = true;
                }else if(points[k]==char('A'+i)){
                    i2 = k;
                }
                if(points[k]==char('A'+j) && !has_j1){
                    j1 = k;
                    has_j1 = true;
                }else if(points[k]==char('A'+j)){
                    j2 = k;
                }
            }
            if(overlap(i1, i2, j1, j2)){
                ++cnt;
            }
        }
    }
    fout << cnt;
}