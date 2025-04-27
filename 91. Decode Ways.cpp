class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        // dp[i] = decode ways for s[i:n]
        for(int i = n-1; i >= 0; --i){
            char c = s[i];
            if(c >= '1' && c <= '9'){
                dp[i] += dp[i+1];
            }
            if(i+1 < n){
                char c2 = s[i+1];
                if(c == '1' || (c == '2' && c2 >= '0' && c2 <= '6'))
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};