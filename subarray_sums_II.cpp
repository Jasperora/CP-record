#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main(){
    ll n, x;
    cin >> n >> x;
    ll prefix_sum = 0;
    ll num, cnt = 0;
    map<ll, int> prefix_sum_cnt;
    prefix_sum_cnt[0] = 1;
    for(int i = 0; i < n; ++i){
        cin >> num;
        prefix_sum += num;

        cnt += prefix_sum_cnt[prefix_sum-x];
        if(!prefix_sum_cnt.count(prefix_sum))
            prefix_sum_cnt[prefix_sum] = 0;
        ++prefix_sum_cnt[prefix_sum];
    }

    cout << cnt;
}