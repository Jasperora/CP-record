class Solution {
public:
    vector<vector<bool> > visited;
    int area = 0;
    void dfs(const vector<vector<int> >& grid, const int& a, const int& b){
        visited[a][b] = true;
        ++area;
        if(a-1>=0&&!visited[a-1][b]&&grid[a-1][b]) dfs(grid, a-1, b);
        if(a+1<grid.size()&&!visited[a+1][b]&&grid[a+1][b]) dfs(grid, a+1, b);
        if(b-1>=0&&!visited[a][b-1]&&grid[a][b-1]) dfs(grid, a, b-1);
        if(b+1<grid[0].size()&&!visited[a][b+1]&&grid[a][b+1]) dfs(grid, a, b+1);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited.resize(grid.size());
        for(int i = 0; i < visited.size(); ++i){
            visited[i].resize(grid[0].size());
        }
        for(int i = 0; i < visited.size(); ++i){
            for(int j = 0; j < visited[0].size(); ++j){
                visited[i][j] = false;
            }
        }
        int ret = 0;
        for(int i = 0; i < visited.size(); ++i){
            for(int j = 0; j < visited[0].size(); ++j){
                if(grid[i][j]&&!visited[i][j]){
                    dfs(grid, i, j);
                    ret = max(ret, area);
                    area = 0;
                }
            }
        }
        return ret;
    }
};
