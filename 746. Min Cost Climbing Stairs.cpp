class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost[cost.size()];
        min_cost[0] = min_cost[1] = 0;
        for(int i = 2; i < cost.size(); ++i){
            min_cost[i] = min(min_cost[i-2]+cost[i-2], min_cost[i-1]+cost[i-1]);
        }
        return min(min_cost[cost.size()-2]+cost[cost.size()-2], min_cost[cost.size()-1]+cost[cost.size()-1]);
    }
};
