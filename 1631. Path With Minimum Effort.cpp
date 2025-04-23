class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
            int m = heights.size(), n = heights[0].size();
            minHeap.push({0, 0, 0});
            vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
            efforts[0][0] = 0;
            vector<pair<int, int>> dirs(4);
            dirs[0] = {-1, 0};
            dirs[1] = {1, 0};
            dirs[2] = {0, -1};
            dirs[3] = {0, 1}; 
            while(!minHeap.empty()){
                int effort = minHeap.top()[0], i = minHeap.top()[1], j = minHeap.top()[2];
                if(i == m-1 && j == n-1) return effort;
                minHeap.pop();
                for(int k = 0; k < 4; ++k){
                    int next_i = i + dirs[k].first;
                    int next_j = j + dirs[k].second;
                    if(next_i >= 0 && next_i < m && next_j >= 0 && next_j < n){
                        int new_effort = max(effort, abs(heights[next_i][next_j] - heights[i][j]));
                        if(new_effort < efforts[next_i][next_j]){
                            efforts[next_i][next_j] = new_effort;
                            minHeap.push({efforts[next_i][next_j], next_i, next_j});
                        }
                    }
                }
            }
            // impossible to be here
            return -1;
        }
    };