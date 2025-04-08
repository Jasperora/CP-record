class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> ret;
            int i = 0;
            int n = intervals.size();
            while(i < n && intervals[i][1] < newInterval[0]){
                ret.push_back(intervals[i]);
                ++i;
            }
            if(i < n){
                if(intervals[i][0] > newInterval[1]){
                    ret.push_back(newInterval);
                }else{
                    ret.push_back({min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])});
                    ++i;
                }
            }else{
                ret.push_back(newInterval);
            }
            while(i < n){
                if(!ret.empty() && ret.back()[1] >= intervals[i][0]){
                    ret.back()[1] = max(ret.back()[1], intervals[i][1]);
                }else{
                    ret.push_back(intervals[i]);
                }
                ++i;
            }
            return ret;
        }
    };