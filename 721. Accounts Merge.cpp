class UnionFind {
public:
    vector<int> rank;
    vector<int> root;
    int size;
    UnionFind(int size){
        this->size = size;
        rank.resize(size, 1);
        root.resize(size);
        for(int i = 0; i < size; ++i){
            root[i] = i;
        }
    }
    int find(int x){
        if(x != root[x])
            root[x] = find(root[x]);
        return root[x];
    }
    bool unionSet(int x, int y){
        // false if not the same set
        // true if in the same set
        int rootX = find(x), rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            }else if(rank[rootY] < rank[rootX]){
                root[rootY] = rootX;
            }else{
                root[rootX] = rootY;
                ++rank[rootY];
            }
            return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToIdx;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                if(emailToIdx.count(accounts[i][j])){
                    // i: current index
                    // emailToIdx[accounts[i][j]]: index that has the same person
                    uf.unionSet(i, emailToIdx[accounts[i][j]]);
                }else{
                    emailToIdx[accounts[i][j]] = i;
                }
            }
        }
        vector<vector<string>> ret;
        // map root index to index in ret
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i){
            if(uf.root[i] == i){
                m[i] = ret.size();
                ret.push_back({accounts[i][0]});
            }
        }
        for(auto& [email, idx_of_email] : emailToIdx){
            int root_idx = uf.find(idx_of_email);
            // should put email under the name with real_idx
            ret[m[root_idx]].push_back(email);
        }
        for(auto& r : ret){
            sort(r.begin() + 1, r.end());
        }
        return ret;
    }
};