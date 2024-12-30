#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    ll a, prefix_sum[N+1];
    prefix_sum[0] = 0;
    for(int i = 1; i <= N; ++i){
        cin >> a;
        if(i==1) prefix_sum[i] = a;
        else prefix_sum[i] = prefix_sum[i-1] + a;
    }
    // for(int i = 0; i < N+1; ++i){
    //     cout << prefix_sum[i] << ' ';
    // }
    for(int i = 0; i < Q; ++i){
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l] << '\n';
    }

}