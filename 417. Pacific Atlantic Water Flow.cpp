class Solution {
public:
    set<vector<int> > pacific, atlantic;
    int m, n;
    void dfs(int i, int j, set<vector<int> >& visited, const vector<vector<int>>& heights, int prev_height){
        if(i<0||j<0||i==m||j==n||heights[i][j]<prev_height||visited.count({i, j}))
            return;
        else{
            visited.insert({i, j});
            dfs(i+1, j, visited, heights, heights[i][j]);
            dfs(i-1, j, visited, heights, heights[i][j]);
            dfs(i, j+1, visited, heights, heights[i][j]);
            dfs(i, j-1, visited, heights, heights[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        for(int i = 0; i < m; ++i){
            dfs(i, 0, pacific, heights, heights[i][0]);
            dfs(i, n-1, atlantic, heights, heights[i][n-1]);
        }
        for(int i = 0; i < n; ++i){
            dfs(0, i, pacific, heights, heights[0][i]);
            dfs(m-1, i, atlantic, heights, heights[m-1][i]);
        }
        vector<vector<int> > ret;
        for(auto& p : pacific){
            if(atlantic.count(p)){
                ret.push_back(p);
            }
        }
        return ret;
    }
};
