#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        ll ps[n+1];
        ps[0] = 0;
        char c;
        map<ll, ll> ps_cnt;
        ps_cnt[0] = 1;
        ll ans = 0;
        for(ll j = 0; j < n; ++j){
            cin >> c;
            // for(auto& p : ps_cnt) cout << p.first << ' ' << p.second << '\n';
            // cout << '\n';
            ps[j+1] = ll(c-'0') + ps[j];
            ans += ps_cnt[ps[j+1]-(j+1)];
            ++ps_cnt[ps[j+1]-(j+1)];
        }
        cout << ans << '\n';
    }
}