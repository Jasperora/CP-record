class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int> > q;
        int fresh = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]==2)
                    q.push({i, j});
                if(grid[i][j]==1)
                    ++fresh;
            }
        }
        int time = 0;
        while(!q.empty()){
            int l = q.size();
            bool not_done = false;
            for(int k = 0; k < l; ++k){
                int i = q.front()[0];
                int j = q.front()[1];
                if(i!=0&&grid[i-1][j]==1){
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                    --fresh;
                    not_done = true;
                }
                if(i!=m-1&&grid[i+1][j]==1){
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                    --fresh;
                    not_done = true;
                }
                if(j!=0&&grid[i][j-1]==1){
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                    --fresh;
                    not_done = true;
                }
                if(j!=n-1&&grid[i][j+1]==1){
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                    --fresh;
                    not_done = true;
                }
                q.pop();
            }
            if(not_done)
                ++time;
        }
        if(fresh) return -1;
        return time;
    }
};
