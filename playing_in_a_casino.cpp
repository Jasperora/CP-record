#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll sum = 0;
        int n, m;
        cin >> n >> m;

        ll num[m][n];
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
                cin >> num[k][j];
            }
        }
        for(int j = 0; j < m; ++j){
            sort(num[j], num[j] + n);
        }

        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << num[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        ll sum_num[n];
        fill(sum_num, sum_num+n, 0);
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
                sum_num[j] += num[k][j];
            }
        }

        // for(int j = 0; j < n; ++j){
        //     cout << sum_num[j] << '\n';
        // }

        for(int j = 0; j < n; ++j){
            sum += (j-(n-j-1)) * sum_num[j];
        }
        cout << sum << '\n';
    }
}