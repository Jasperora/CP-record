class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ret;
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0]<=ret[ret.size()-1][1]){
                vector<int> combined = {ret[ret.size()-1][0], max(intervals[i][1], ret[ret.size()-1][1])};
                ret.pop_back();
                ret.push_back(combined);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};
