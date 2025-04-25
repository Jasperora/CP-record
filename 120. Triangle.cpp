// space optimized bottom-up dp
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle.back();
        // (n-1)-th row are correct
        // start from (n-2)-th row
        for(int i = n-2; i >= 0; --i){
            for(int j = 0; j < i+1; ++j){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
// bottom-up dp
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        // (n-1)-th row are correct
        // start from (n-2)-th row
        for(int i = n-2; i >= 0; --i){
            for(int j = 0; j < i+1; ++j){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
// top-down dp
class Solution3 {
public:
    vector<vector<int>> dp;
    int n;
    int dfs(const vector<vector<int>>& triangle, int layer, int idx){
        if(layer >= n) return 0;
        if(dp[layer][idx] != INT_MAX)
            return dp[layer][idx];
        dp[layer][idx] = triangle[layer][idx] + min(dfs(triangle, layer + 1, idx), dfs(triangle, layer + 1, idx + 1));
        return dp[layer][idx];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.resize(n, vector<int>(n, INT_MAX));
        return dfs(triangle, 0, 0);
    }
};