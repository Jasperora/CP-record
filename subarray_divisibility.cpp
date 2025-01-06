#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main(){
    ll n, x;
    cin >> n;
    ll prefix_sum = 0;
    ll num, cnt = 0;
    map<ll, int> prefix_sum_cnt;
    prefix_sum_cnt[0] = 1;
    for(ll i = 1; i < n; ++i) prefix_sum_cnt[i] = 0;
    for(ll i = 0; i < n; ++i){
        cin >> num;
        prefix_sum += num;

        // for(auto& p : prefix_sum_cnt) cout << p.first << ' ' << p.second << '\n';
        // cout << '\n';
        
        ll r = prefix_sum % n;
        if(r < 0)
            cnt += prefix_sum_cnt[r + n];
        else cnt += prefix_sum_cnt[r];

        if(r < 0) ++prefix_sum_cnt[r + n];
        else ++prefix_sum_cnt[r];
    }
    cout << cnt;
}