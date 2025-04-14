#define ll long long
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<vector<int>> index_tasks;
        int n = tasks.size();
        for(int i = 0; i < n; ++i)
            index_tasks.push_back({tasks[i][0], tasks[i][1], i});
        sort(index_tasks.begin(), index_tasks.end());
        int idx = 0;
        ll curTime = 0;

        vector<int> ret;
        while(idx < n || !minHeap.empty()){
            while(idx < n && index_tasks[idx][0] <= curTime){
                // processTime, idx
                minHeap.push({index_tasks[idx][1], index_tasks[idx][2]});
                ++idx;
            }
            if(idx < n && minHeap.empty()){
                minHeap.push({index_tasks[idx][1], index_tasks[idx][2]});
                curTime = index_tasks[idx][0];
                ++idx;
            }
            ret.push_back(minHeap.top().second);
            curTime += minHeap.top().first;
            minHeap.pop();
        }
        return ret;
    }
};