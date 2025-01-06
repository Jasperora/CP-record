#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int N;
    fin >> N;
    char gestures[N];
    int H_cnt[N+1], P_cnt[N+1], S_cnt[N+1];
    H_cnt[0] = P_cnt[0] = S_cnt[0] = 0;
    for(int i = 0; i < N; ++i){
        fin >> gestures[i];
        H_cnt[i+1] = H_cnt[i];
        P_cnt[i+1] = P_cnt[i];
        S_cnt[i+1] = S_cnt[i];
        if(gestures[i]=='H'){
            ++H_cnt[i+1];
        }else if(gestures[i]=='P'){
            ++P_cnt[i+1];
        }else{
            ++S_cnt[i+1];
        }
    }
    // for(int i = 0; i < N+1; ++i){
    //     cout << H_cnt[i] << ' ' << P_cnt[i] << ' ' << S_cnt[i] << '\n';
    // }
    int sum = 0;
    for(int i = 0; i <= N; ++i){
        if(P_cnt[i]+S_cnt[N]-S_cnt[i]>sum) sum = P_cnt[i]+S_cnt[N]-S_cnt[i];
        if(S_cnt[i]+P_cnt[N]-P_cnt[i]>sum) sum = S_cnt[i]+P_cnt[N]-P_cnt[i];
        if(P_cnt[i]+H_cnt[N]-H_cnt[i]>sum) sum = P_cnt[i]+H_cnt[N]-H_cnt[i];
        if(H_cnt[i]+P_cnt[N]-P_cnt[i]>sum) sum = H_cnt[i]+P_cnt[N]-P_cnt[i];
        if(H_cnt[i]+S_cnt[N]-S_cnt[i]>sum) sum = H_cnt[i]+S_cnt[N]-S_cnt[i];
        if(S_cnt[i]+H_cnt[N]-H_cnt[i]>sum) sum = S_cnt[i]+H_cnt[N]-H_cnt[i];
    }
    fout << sum;

}