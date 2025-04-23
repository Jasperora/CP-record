class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            if(n == 1) return {0};
            vector<unordered_set<int>> adj(n);
            for(auto& edge : edges){
                adj[edge[0]].insert(edge[1]);
                adj[edge[1]].insert(edge[0]);
            }
            queue<int> leaves;
            for(int i = 0; i < n; ++i){
                if(adj[i].size() == 1){
                    leaves.push(i);
                }
            }
            while(n > 2){
                int size = leaves.size();
                n -= size;
                for(int i = 0; i < size; ++i){
                    int front = leaves.front();
                    leaves.pop();
                    for(auto& neighbor : adj[front]){
                        adj[neighbor].erase(front);
                        if(adj[neighbor].size() == 1)
                            leaves.push(neighbor);
                    }
                }
            }
            vector<int> ret;
            while(leaves.size()){
                ret.push_back(leaves.front());
                leaves.pop();
            }
            return ret;
        }
    };