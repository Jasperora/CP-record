// sliding window
class Solution1 {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts - 1) return 1.0;
        vector<double> dp(k + maxPts, 0);
        for(int i = k; i <= n; ++i)
            dp[i] = 1;
        for(int i = n + 1; i < k + maxPts; ++i)
            dp[i] = 0;

        //                 k                     n         k + maxPts - 1
        // 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
        //               |
        //          start from here
        double window_sum = 0;
        for(int i = k; i < k + maxPts; ++i)
            window_sum += dp[i];
        for(int i = k - 1; i >= 0; --i){
            dp[i] = window_sum / maxPts;
            window_sum -= dp[i + maxPts];
            window_sum += dp[i];
        }
        return dp[0];
    }
};
// vanilla dp
// TLE
class Solution2 {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts - 1) return 1.0;

        // at most draw maxPts at k-1 points
        vector<double> dp(k + maxPts, 0);
        dp[0] = 1;
        // return sum of dp[k] ~ dp[n] when dp[0:k] are all zero
        // each time the point will increase at leat k
        // so at most k steps would be enough
        int tmp = k;
        while(tmp--){
            vector<double> new_dp(k + maxPts, 0);
            for(int i = k; i < k + maxPts; ++i){
                new_dp[i] = dp[i];
            }
            for(int i = 0; i < k; ++i){
                if(dp[i]){
                    double prob = dp[i] / maxPts;
                    for(int j = i + 1; j <= i + maxPts; ++j){
                        new_dp[j] += prob;
                    }
                    dp[i] = 0;
                }
            }
            swap(dp, new_dp);
        }
        double ret = 0;
        for(int i = k; i <= n; ++i)
            ret += dp[i];
        return ret;
    }
};