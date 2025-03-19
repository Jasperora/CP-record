#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll sum = (n*(n+1))>>1;
    for(int i = 1; i <= n-1; ++i){
        ll x;
        cin >> x;
        sum -= x;
    }
    cout << sum;
}