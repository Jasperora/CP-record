class UnionFind {
public:
    vector<int> root;
    vector<int> rank;
    int size;
    UnionFind(int size){
        this->size = size;
        root.resize(size);
        rank.resize(size, 1);
        for(int i = 0; i < size; ++i)
            root[i] = i;
    }
    int find(int x){
        if(x != root[x])
            root[x] = find(root[x]);
        return root[x];
    }
    bool unionSet(int x, int y){
        int rootX = find(x), rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            }else if(rank[rootX] > rank[rootY]){
                root[rootY] = rootX;
            }else{
                root[rootX] = rootY;
                ++rank[rootY];
            }
            // different disjoint set
            return false;
        }
        // same disjoint set
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for(auto& e : edges){
            if(uf.unionSet(e[0] - 1, e[1] - 1))
                return {e[0], e[1]};
        }

        // impossible to be here
        return {};
    }
};