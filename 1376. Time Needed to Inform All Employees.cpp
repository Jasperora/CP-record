class Solution {
    public:
        vector<vector<int>> adj;
        int dfs(int employee, const vector<vector<int>>& adj, const vector<int>& informTime){
            int max_time = 0;
            for(auto& subordinate : adj[employee]){
                max_time = max(max_time, dfs(subordinate, adj, informTime));
            }
            max_time += informTime[employee];
            return max_time;
        }
        int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            adj.resize(n);
            for(int i = 0; i < n; ++i){
                if(i == headID) continue;
                adj[manager[i]].push_back(i);
            }
            return dfs(headID, adj, informTime);
        }
    };