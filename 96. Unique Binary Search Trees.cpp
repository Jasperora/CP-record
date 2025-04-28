// 1D dp
class Solution1 {
public:
    int numTrees(int n) {
        // 2D dp will record same values for many different cases
        // dp[i] = number of unique BSTs with i nodes
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
// 2D dp
class Solution2 {
public:
    int size;
    vector<vector<int>> dp;
    int dfs(int start, int end){
        if(start == end)
            // one node
            return dp[start][end] = 1;
        if(start > end)
            // nullptr
            return 1;
        if(dp[start][end] != 0)
            return dp[start][end];

        for(int i = start; i <= end; ++i){
            // use i as root
            dp[start][end] += dfs(start, i-1) * dfs(i+1, end);
        }
        return dp[start][end];
    }
    int numTrees(int n) {
        size = n;
        dp.resize(n, vector<int>(n, 0));
        return dfs(0, n-1);
    }
};