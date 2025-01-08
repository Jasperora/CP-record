#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        int N;
        cin >> N;
        ll a[N];
        ll sum = 0;
        ll max = -1;
        for(int j = 0; j < N ; ++j){
            cin >> a[j];
            if(a[j]>max) max = a[j]; 
            sum += a[j];
        }
        if(max==0) cout << 0 << '\n';
        else{
            for(int j = max; j <= sum; ++j){
                if(sum%j==0){
                    ll tmp = 0;
                    // cout << j << '\n';
                    for(int k = 0; k < N; ++k){
                        if(tmp<j) tmp += a[k];
                        if(tmp>j) break;
                        if(tmp==j){
                            tmp = 0;
                        }
                        // cout << j << ": " << k << ' ' << tmp << '\n';
                    }
                    if(tmp==0){
                        cout << N - int(sum/j) << '\n';
                        break;
                    }
                }
            }
        }

    }
}