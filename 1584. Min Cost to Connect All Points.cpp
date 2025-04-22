// Kruskal's algorithm
class UnionFind{
public:
    vector<int> rank;
    vector<int> root;
    int size;
    UnionFind(int n){
        size = n;
        rank.resize(n, 1);
        root.resize(n);
        for(int i = 0; i < n; ++i)
            root[i] = i;
    }
    int find(int idx){
        if(idx != root[idx])
            root[idx] = find(root[idx]);
        return root[idx];
    }
    bool unionSet(int i, int j){
        // return false if originally not the same set
        // return true if they are at the same set
        int rootI = find(i), rootJ = find(j);
        if(rootI != rootJ){
            if(rank[rootI] > rank[rootJ]){
                root[rootJ] = rootI;
            }else if(rank[rootJ] > rank[rootI]){
                root[rootI] = rootJ;
            }else{
                root[rootJ] = rootI;
                ++rank[rootI];
            }
            return false;
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UnionFind uf(n);
        // cost, u, v
        vector<vector<int>> edges;
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int ret = 0;
        for(int i = 0; i < edges.size(); ++i){
            // need this edge
            if(!uf.unionSet(edges[i][1], edges[i][2]))
                ret += edges[i][0];
        }
        return ret;
    }
};
// Prim's algorithm
class Solution2 {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // cost, point idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int n = points.size();
        vector<bool> visited(n, false);
        minHeap.push({0, 0});
        int ret = 0;
        int MSTsize = 0;
        while(MSTsize != n && !minHeap.empty()){
            auto [cost, idx] = minHeap.top();
            minHeap.pop();
            // because one point might be added several times
            // need a check
            if(visited[idx]) continue;

            visited[idx] = true;
            ret += cost;
            ++MSTsize;
            for(int i = 0; i < n; ++i){
                if(!visited[i]){
                    int newCost = abs(points[idx][0] - points[i][0]) + abs(points[idx][1] - points[i][1]);
                    minHeap.push({newCost, i});
                }
            }
        }
        return ret;
    }
};