class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());

        map<int, int> tmp;
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > min_heap;
        int i = 0;
        for(auto& q : sorted_queries){
            while(i<intervals.size() && intervals[i][0]<=q){
                min_heap.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                ++i;
            }
            while(!min_heap.empty() && min_heap.top()[1]<q){
                min_heap.pop();
            }
            if(min_heap.empty()) tmp[q] = -1;
            else tmp[q] = min_heap.top()[0];
        }
        vector<int> ret;
        for(auto& q : queries){
            ret.push_back(tmp[q]);
        }
        return ret;
    }
};
