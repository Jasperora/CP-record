class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        stack<vector<int> > s;
        for(int i = 0; i < intervals.size(); ++i){
            if(s.empty()){
                s.push(intervals[i]);
            }else{
                if(intervals[i][0]<=s.top()[1]){
                    vector<int> combined = {s.top()[0], max(s.top()[1], intervals[i][1])};
                    s.pop();
                    s.push(combined);
                }else{
                    s.push(intervals[i]);
                }
            }
        }
        intervals.resize(s.size());
        for(int i = intervals.size()-1; i >= 0; --i){
            intervals[i] = s.top();
            s.pop();
        }
        return intervals;
    }
};
