class Solution {
private:
    vector<vector<int> > dp;
    int m, n;
    int dfs(int i, int j, const vector<vector<int> >& matrix){
        if(i<0||j<0||i==m||j==n) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        int ret = 1;
        if(i+1<m && matrix[i][j]<matrix[i+1][j]) ret = max(ret, 1+dfs(i+1, j, matrix));
        if(i-1>=0 && matrix[i][j]<matrix[i-1][j]) ret = max(ret, 1+dfs(i-1, j, matrix));
        if(j+1<n && matrix[i][j]<matrix[i][j+1]) ret = max(ret, 1+dfs(i, j+1, matrix));
        if(j-1>=0 && matrix[i][j]<matrix[i][j-1]) ret = max(ret, 1+dfs(i, j-1, matrix));
        dp[i][j] = ret;
        return ret;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));
        int ret = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ret = max(ret, dfs(i, j, matrix));
            }
        }
        return ret;
    }
};
