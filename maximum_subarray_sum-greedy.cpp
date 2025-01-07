#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    ll x[n];
    for(int i = 0; i < n; ++i) cin >> x[i];
    ll max_sub_sum_cur, ans;
    max_sub_sum_cur = ans = x[0];
    for(int i = 1; i < n; ++i){
        if(x[i]+max_sub_sum_cur > x[i])
            max_sub_sum_cur = x[i]+max_sub_sum_cur;
        else max_sub_sum_cur = x[i];
        if(max_sub_sum_cur>ans)
            ans = max_sub_sum_cur;
    }
    cout << ans;
}