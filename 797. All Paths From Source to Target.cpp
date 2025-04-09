class Solution {
    public:
        vector<vector<int>> ret;
        vector<int> path;
        void dfs(const vector<vector<int>>& adj, int cur, int dst){
            path.push_back(cur);
            if(cur == dst){
                ret.push_back(path);
            }
    
            for(auto& neighbor : adj[cur]){
                dfs(adj, neighbor, dst);
            }
            path.pop_back();
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            dfs(graph, 0, graph.size()-1);
            return ret;
        }
    };