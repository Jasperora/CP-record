#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    ll mul;
    for(int i = 0; i < n; ++i){
        mul = (i+1) * (n-i);
        a[i] *= mul;
    }
    sort(a, a+n);
    sort(b, b+n);
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i]*b[n-1-i];
    }
    cout << sum;
}