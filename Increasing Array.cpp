#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll mx = 0, ret = 0;
    for(int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        mx = max(mx, x);
        ret += mx-x;
    }
    cout << ret;
}