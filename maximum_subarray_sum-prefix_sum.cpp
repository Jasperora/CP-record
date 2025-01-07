#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll x;
    ll ps[n+1];
    ps[0] = 0;
    ll min_ps = 0;
    ll ans;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        if(i==1) ans = x;
        ps[i] = ps[i-1] + x;
        if(ps[i]-min_ps>ans) ans = ps[i]-min_ps;
        if(ps[i]<min_ps) min_ps = ps[i];
    }
    cout << ans;
}