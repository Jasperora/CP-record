class Solution {
public:
    set<int> not_visited;
    vector<vector<int> > adj;
    void dfs(int root, int prev){
        if(!not_visited.count(root)){
            return;
        }else{
            not_visited.erase(root);
            for(auto& neighbor : adj[root]){
                if(neighbor==prev) continue;
                dfs(neighbor, root);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; ++i) not_visited.insert(i);
        adj.resize(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ret = 0;
        while(!not_visited.empty()){
            ++ret;
            for(auto& node : not_visited){
                dfs(node, -1);
                break;
            }
        }
        return ret;
    }
};
