class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int> > q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]==0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            if(!visited[i][j]){
                visited[i][j] = true;
                if(i>0 && grid[i-1][j]!=-1 && !visited[i-1][j]){
                    grid[i-1][j] = min(grid[i-1][j], grid[i][j] + 1);
                    q.push({i-1, j});
                }
                if(i<grid.size()-1 && grid[i+1][j]!=-1 && !visited[i+1][j]){
                    grid[i+1][j] = min(grid[i+1][j], grid[i][j] + 1);
                    q.push({i+1, j});
                }
                if(j>0 && grid[i][j-1]!=-1 && !visited[i][j-1]){
                    grid[i][j-1] = min(grid[i][j-1], grid[i][j] + 1);
                    q.push({i, j-1});
                }
                if(j<grid[0].size()-1 && grid[i][j+1]!=-1 && !visited[i][j+1]){
                    grid[i][j+1] = min(grid[i][j+1], grid[i][j] + 1);
                    q.push({i, j+1});
                }
                // for(int i = 0; i < m; ++i){
                //     for(int j = 0; j < n; ++j){
                //         cout << grid[i][j] << ' ';
                //     }
                //     cout << '\n';
                // }
                // cout << "========\n";
            }
            q.pop();
        }
    }
};
