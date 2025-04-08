class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
    
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(mat[i][j] == 0){
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
            while(!q.empty()){
                int q_len = q.size();
                while(q_len--){
                    pair<int, int> p = q.front();
                    q.pop();
                    if(p.first-1 >= 0 && !visited[p.first-1][p.second]){
                        mat[p.first-1][p.second] = mat[p.first][p.second] + 1;
                        visited[p.first-1][p.second] = true;
                        q.push({p.first-1, p.second});
                    }
                    if(p.first+1 < m && !visited[p.first+1][p.second]){
                        mat[p.first+1][p.second] = mat[p.first][p.second] + 1;
                        visited[p.first+1][p.second] = true;
                        q.push({p.first+1, p.second});
                    }
                    if(p.second-1 >= 0 && !visited[p.first][p.second-1]){
                        mat[p.first][p.second-1] = mat[p.first][p.second] + 1;
                        visited[p.first][p.second-1] = true;
                        q.push({p.first, p.second-1});
                    }
                    if(p.second+1 < n && !visited[p.first][p.second+1]){
                        mat[p.first][p.second+1] = mat[p.first][p.second] + 1;
                        visited[p.first][p.second+1] = true;
                        q.push({p.first, p.second+1});
                    }
                }
            }
            return mat;
        }
    };