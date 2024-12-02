#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;
    int p[N];
    char c[N];
    for(int i = 0; i < N; ++i){
        cin >> c[i] >> p[i];
    }

    int tmp, cnt = 10001;
    for(int i = 0; i < N; ++i){
        tmp = 0;
        for(int j = 0; j < N; ++j){
            if((c[j]=='L' && p[i]>p[j]) || (c[j]=='G' && p[i]<p[j]))
                ++tmp;
            
        }
        if(tmp < cnt) cnt = tmp;
    }
    cout << cnt;

}