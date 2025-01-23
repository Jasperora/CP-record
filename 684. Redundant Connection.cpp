class Solution {
private:
    vector<int> ret;
    // find parent
    int find(int i){
        while(i!=parent[i]){
            i = parent[i];
        }
       return i;
    }
    void union_combine(int a, int b){
        if(find(a)==find(b)){
            ret = {a, b};
            return;
        }else{
            if(rank[find(a)]==rank[find(b)]){
                ++rank[find(a)];
                parent[find(b)] = find(a);
            }else if(rank[find(a)]>rank[find(b)]){
                ++rank[find(a)];
                parent[find(b)] = find(a);
            }else{
                ++rank[find(b)];
                parent[find(a)] = find(b);
            }
        }
    }
public:
    vector<int> parent, rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1; i <= n; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto& e : edges){
            union_combine(e[0], e[1]);
        }
        return ret;
    }
};
