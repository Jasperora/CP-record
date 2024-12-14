#include <iostream>
#include <fstream>
using namespace std;



int main(){
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int N;
    fin >> N;

    int time[N][2];

    for(int i = 0; i < N; ++i){
        fin >> time[i][0] >> time[i][1];
    }

    int max = -1;
    for(int i = 0; i < N; ++i){
        bool range[1001] = {false};
        for(int j = 0; j < N; ++j){
            if(j==i) continue;
            for(int k = time[j][0]; k < time[j][1]; ++k){
                range[k] = true;
            }
        }
        int tmp = 0;
        for(int j = 0; j < 1001; j++){
            tmp += range[j];
        }
        if(tmp > max) max = tmp;
    }
    fout << max;
}