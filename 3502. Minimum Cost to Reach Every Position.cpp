class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            vector<int> ret(cost.size());
            int mn = INT_MAX;
            for(int i = 0; i < cost.size(); ++i){
                mn = min(mn, cost[i]);
                ret[i] = mn;
            }
            return ret;
        }
    };