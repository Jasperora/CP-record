#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;
    ll d[N];
    for(ll i = 0; i < N; ++i) cin >> d[i];
    
    ll total = 1 + K;
    for(ll i = 1; i < N; ++i){
        if(1+K < d[i]-d[i-1]){
            total += 1+K;
        }else{
            total += d[i]-d[i-1];
        }
    }
    cout << total;
}