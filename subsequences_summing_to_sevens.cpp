#include <iostream>
#include <fstream>
using namespace std;
using ll = long long;

int main(){
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int N;
    fin >> N;
    ll num[N], prefix_sum[N+1];
    prefix_sum[0] = 0;
    for(int i = 0; i < N; ++i){
        fin >> num[i];
        prefix_sum[i+1] = prefix_sum[i] + num[i];
    }
    for(int i = N; i >= 0; --i){
        for(int j = 0; j <= N-i; ++j){
            if(!((prefix_sum[N-j]-prefix_sum[N-j-i])%7)){
                fout << i;
                return 0;
            }
        }
    }
}