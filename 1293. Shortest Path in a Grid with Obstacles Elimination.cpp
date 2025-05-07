class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // i, j, dist, used_k
        queue<vector<int>> q;
        if(grid[0][0] == 1 && k == 0) return -1;
        // need 3D visited
        // to record additional k
        // visited states could be revisit but with different used_k
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        if(grid[0][0] == 1){
            q.push({0, 0, 0, 1});
            visited[0][0][1] = true;
        }else{
            q.push({0, 0, 0, 0});
            visited[0][0][0] = true;
        }
        pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                vector<int> front = q.front();
                q.pop();
                if(front[0] == m-1 && front[1] == n-1)
                    return front[2];
                for(auto& dir: dirs){
                    int next_i = front[0] + dir.first;
                    int next_j = front[1] + dir.second;
                    if(next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && !visited[next_i][next_j][front[3]]){
                        int new_eliminated = front[3] + grid[next_i][next_j];
                        if(new_eliminated <= k && !visited[next_i][next_j][new_eliminated]){
                            visited[next_i][next_j][new_eliminated] = true;
                            q.push({next_i, next_j, front[2]+1, new_eliminated});
                        }
                    }
                }
            }
        }
        return -1;
    }
};