class Solution {
public:
    vector<vector<bool> > visited;
    void dfs(const vector<vector<char> >& grid, const int& a, const int& b){
        visited[a][b] = true;
        if(a-1>=0&&!visited[a-1][b]&&grid[a-1][b]=='1') dfs(grid, a-1, b);
        if(a+1<grid.size()&&!visited[a+1][b]&&grid[a+1][b]=='1') dfs(grid, a+1, b);
        if(b-1>=0&&!visited[a][b-1]&&grid[a][b-1]=='1') dfs(grid, a, b-1);
        if(b+1<grid[0].size()&&!visited[a][b+1]&&grid[a][b+1]=='1') dfs(grid, a, b+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        visited.resize(grid.size());
        for(int i = 0; i < visited.size(); ++i){
            visited[i].resize(grid[0].size());
        }
        int ret = 0;
        for(int i = 0; i < visited.size(); ++i){
            for(int j = 0; j < visited[0].size(); ++j){
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < visited.size(); ++i){
            for(int j = 0; j < visited[0].size(); ++j){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    ++ret;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
};
