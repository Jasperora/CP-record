#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int N, Q;
    fin >> N >> Q;
    map<int, int> cnt[N+1];
    cnt[0][1] = cnt[0][2] = cnt[0][3] = 0;
    int num;
    for(int i = 1; i <= N; ++i){
        fin >> num;
        for(int j = 1; j <= 3; ++j){
            if(j==num) cnt[i][j] = cnt[i-1][j] + 1;
            else cnt[i][j] = cnt[i-1][j];
        }
    }
    int a, b;
    for(int i = 0; i < Q; ++i){
        fin >> a >> b;
        fout << cnt[b][1] - cnt[a-1][1] << ' ' << cnt[b][2] - cnt[a-1][2] << ' ' << cnt[b][3] - cnt[a-1][3];
        fout << '\n';
    }
}