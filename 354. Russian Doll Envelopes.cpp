// O(nlogn) longest increasing subsequence
class Solution1 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // [1, 2], [2, 3], [3, 4], [3, 2], [4, 5]
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        // monotonic increasing
        vector<int> stack;
        for(auto& env: envelopes){
            if(stack.empty() || env[1] > stack.back()){
                stack.push_back(env[1]);
            }else{
                auto iter = lower_bound(stack.begin(), stack.end(), env[1]);
                *iter = env[1];
            }
        }
        return stack.size();
    }
};
// O(n^2) longest increasing subsequence
// TLE
class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j){
                if(envelopes[i][1] < envelopes[j][1] && envelopes[i][0] < envelopes[j][0]){
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; ++i){
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};