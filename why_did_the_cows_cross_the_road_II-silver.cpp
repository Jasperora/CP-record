#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");

    int N, K, B;
    fin >> N >> K >> B;
    bool broken[N+1];
    for(int i = 0; i < N+1; ++i)
        broken[i] = false;
    
    int b;
    for(int i = 0; i < B; ++i){
        fin >> b;
        broken[b] = true;
    }

    int prefix_sum[N+1];
    prefix_sum[0] = 0;
    for(int i = 1; i <= N; ++i){
        prefix_sum[i] = broken[i] + prefix_sum[i-1];
    }
    // for(int i = 0; i <= N; ++i){
    //     cout << prefix_sum[i] << ' ';
    // }
    // cout << '\n';

    int min_broken = K;
    for(int i = 0; i+K <= N; ++i){
        int broken_num = prefix_sum[i+K] - prefix_sum[i];
        if(broken_num < min_broken) min_broken = broken_num;
    }
    
    fout << min_broken;
}