class Solution {
    public:
        int maxScoreSightseeingPair(vector<int>& values) {
            int ret = INT_MIN;
            int cur_max = values[0];
            for(int i = 1; i < values.size(); ++i){
                ret = max(ret, cur_max+values[i]-i);
                cur_max = max(cur_max, values[i]+i);
            }
            return ret;
        }
    };