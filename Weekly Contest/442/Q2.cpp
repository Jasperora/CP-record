class Solution {
    public:
        int kk;
        bool t(const unordered_set<int>& aa, const unordered_set<int>& bb){
            int ret = 0;
            for(auto& i : aa){
                if(bb.count(i)){
                    ++ret;
                    if(ret>=kk) return true;
                }
            }
            return false;
        }
        unordered_set<int> seen;
        vector<vector<int>> adj;
        int dfs(int i){
            if(seen.count(i)) return 0;
            else{
                seen.insert(i);
                for(auto& n : adj[i]){
                    dfs(n);
                }
                return 1;
            }
        }
        int numberOfComponents(vector<vector<int>>& properties, int k) {
            int n = properties.size();
            adj.resize(n);
            kk = k;
            vector<unordered_set<int>> vs(n);
            for(int i = 0; i < n; ++i){
                for(auto& j : properties[i])
                    vs[i].insert(j);
            }
            for(int i = 0; i < n-1; ++i){
                for(int j = i+1 ; j < n; ++j){
                    if(t(vs[i], vs[j])){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            int ret = 0;
            for(int i = 0; i < n; ++i){
                ret += dfs(i);
            }
            return ret;
            
        }
    };