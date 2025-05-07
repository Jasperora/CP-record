#define ll long long
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end());
        ll cur_pos = 0, i = 0;
        int n = stations.size();
        vector<bool> add_fuel(n, false);
        int ret = 0;
        while(cur_pos < target){
            cur_pos += startFuel;
            if(cur_pos >= target)
                break;
            int add_idx = -1;
            ll add_num = 0;
            for(int i = 0; i < n && (ll)stations[i][0] <= cur_pos; ++i){
                if(!add_fuel[i] && (ll)stations[i][1] > add_num){
                    add_idx = i;
                    add_num = (ll)stations[i][1];
                }
            }
            if(add_idx == -1 && cur_pos < (ll)target)
                return -1;
            else{
                startFuel = add_num;
                add_fuel[add_idx] = true;
                ++ret;
            }
        }
        return ret;
    }
};