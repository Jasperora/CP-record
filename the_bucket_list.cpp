#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("blist.in");
    ofstream fout("blist.out");

    int N;
    fin >> N;
    int s[N], t[N], b[N];
    for(int i = 0; i < N; ++i)
        fin >> s[i] >> t[i] >> b[i];
    
    int max_bucket_cnt = 0, bucket_cnt;
    for(int i = 1; i <= 1000; ++i){
        bucket_cnt = 0;
        for(int j = 0; j < N; ++j){
            if(i >= s[j] && i <= t[j]){
                bucket_cnt += b[j];
            }
        if(bucket_cnt > max_bucket_cnt) max_bucket_cnt = bucket_cnt;
        }
    }
    fout << max_bucket_cnt;
}