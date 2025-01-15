class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = 0, cost_sum = 0, n = gas.size();
        for(int i = 0; i < n; ++i){
            gas_sum += gas[i];
            cost_sum += cost[i];
        }
        if(gas_sum<cost_sum) return -1;

        int cur = 0, start = 0;
        for(int i = 0; i < n; ++i){
            cur += gas[i]-cost[i];
            if(cur<0){
                cur = 0;
                start = (i+1)%n;
            }
        }
        return start;
    }
};
