// Union Find
class UnionFind {
public:
    vector<int> root;
    vector<int> rank;
    int size;
    UnionFind(int size){
        root.resize(size);
        rank.resize(size, 1);
        for(int i = 0; i < size; ++i)
            root[i] = i;
        this->size = size;
    }
    int find(int node){
        // path compression 
        if(node != root[node])
            root[node] = find(root[node]);
        return root[node];
    }
    bool unionSet(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB){
            if(rank[rootA] < rank[rootB]){
                root[rootA] = rootB;
            }else if(rank[rootA] > rank[rootB]){
                root[rootB] = rootA;
            }else{
                root[rootA] = rootB;
                ++rank[rootB];
                return true;
            }
        }
        return false;
    }
    int countDisjointSet(){
        // count root number
        int ret = 0;
        for(int i = 0; i < size; ++i){
            if(root[i] == i)
                ++ret;
        }
        return ret;
    }
};
class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j]){
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.countDisjointSet();
    }
};
// DFS
class Solution2 {
public:
    int n;
    vector<bool> visited;
    void dfs(const vector<vector<int>>& isConnected, int idx){
        if(visited[idx]) return;
        visited[idx] = true;
        for(int i = 0; i < n; ++i){
            if(isConnected[idx][i]){
                dfs(isConnected, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        visited.resize(n, false);
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                ++ret;
                dfs(isConnected, i);
            }
        }
        return ret;
    }
};
// BFS
class Solution3 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                ++ret;
                visited[i] = true;
                q.push(i);
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    for(int j = 0; j < n; ++j){
                        if(isConnected[front][j] && !visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
        return ret;
    }
};