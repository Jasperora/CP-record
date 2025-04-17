class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int total = 0;
            int cur = 0;
            int ret = 0;
            int n = gas.size();
            for(int i = 0; i < n; ++i){
                total += gas[i] - cost[i];
                cur += gas[i] - cost[i];
                if(cur < 0){
                    // that means that start from ret would fail
                    // because cur should be ≥ 0 after each station
                    // so that start from each station between ret and i would also fail
                    // so change ret = i + 1
                    ret = i + 1;
                    cur = 0;
                }
            }
            return total >= 0 ? ret : -1;
        }
    };