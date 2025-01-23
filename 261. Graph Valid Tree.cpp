class Solution {
public:
    vector<bool> visited;
    vector<vector<int> > adj;
    bool has_cycle = false;
    void dfs(int root){
        if(!visited[root]){
            visited[root] = true;
            for(auto& neighbor: adj[root]){
                remove(adj[neighbor].begin(), adj[neighbor].end(), root);
                adj[neighbor].pop_back();
                dfs(neighbor);
            }
        }else{
            has_cycle = true;
            return;
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n);
        adj.resize(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0);
        if(has_cycle) return false;
        for(int i = 0; i < n; ++i){
            if(!visited[i]) return false;
        }
        return true;
    }
};
