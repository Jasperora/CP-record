class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        // use bitmask to represent tasks subset
        // dp[i] = minimun sessions needed for task subset i
        vector<int> dp(1 << n, n);
        // empty set
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n); ++mask){
            // mask is a subset of tasks
            // iterate all masks
            int mask_needed_time = 0;
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)){
                    // mask contains task i
                    mask_needed_time += tasks[i];
                }
            }
            if(mask_needed_time <= sessionTime){
                dp[mask] = 1;
            }else{
                for(int subset = mask; subset; subset = (subset - 1) & mask){
                    // iterate all subsets of mask
                    dp[mask] = min(dp[mask], dp[mask - subset] + dp[subset]);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};