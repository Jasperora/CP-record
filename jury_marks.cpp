#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    int a[k], b[n], prefix_sum_a[k];
    for(int i = 0; i < k; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    prefix_sum_a[0] = a[0];
    for(int i = 1; i < k; ++i) prefix_sum_a[i] = a[i] + prefix_sum_a[i-1];
    
    set<int> options;
    for(int i = 0; i < k; ++i){
        // note: using only one b is satisfiable
        int possible_options = b[0]-prefix_sum_a[i];
        options.insert(possible_options);
    }
    int ans = 0;
    for(int o : options){
        set<int> traj;
        for(int i = 0; i < k; ++i){
            traj.insert(o+prefix_sum_a[i]);
        }
        bool is_option = true;
        for(int i = 0; i < n; ++i){
            is_option &= traj.count(b[i]);
        }
        ans += is_option;
    }
    cout << ans;
}