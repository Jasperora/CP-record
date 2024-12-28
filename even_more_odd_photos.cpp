#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int odd_cnt = 0, even_cnt = 0;
    int num;
    for(int i = 0; i < N; ++i){
        cin >> num;
        if(num & 1) ++odd_cnt;
        else ++even_cnt;
    }
    int ans = 0;
    while(odd_cnt>0 || even_cnt>0){
        // cout << odd_cnt << ' ' << even_cnt << '\n';
        if(!(ans & 1)){
            if(even_cnt){
                --even_cnt;
                ++ans;
            }else if(odd_cnt > 1){
                odd_cnt -= 2;
                ++ans;
            }else{
                --odd_cnt;
                --ans;
            }
        }else{
            if(odd_cnt){
                --odd_cnt;
                ++ans;
            }else break;
        }
    }
    cout << ans;
}