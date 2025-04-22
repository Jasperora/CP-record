class Solution {
    public:
        vector<int> status;
        stack<int> order;
        bool isSafe(int idx, const vector<vector<int>>& graph){
            if(status[idx] != 0)
                return status[idx] == 2;
            status[idx] = 1;
            for(auto& neighbor : graph[idx]){
                if(!isSafe(neighbor, graph)){
                    status[idx] = 3;
                    return false;
                }
            }
            status[idx] = 2;
            return true;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            // 0: unvisited, 1: visiting, 2: safe, 3: unsafe
            status.resize(n, 0);
            vector<int> ret;
            for(int i = 0; i < n; ++i){
                if(isSafe(i, graph))
                    ret.push_back(i);
            }
            return ret;
        }
    };