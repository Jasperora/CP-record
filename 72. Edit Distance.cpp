class Solution {
    public:
        int minDistance(string word1, string word2) {
            int l1 = word1.size(), l2 = word2.size();
            vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
            for(int j = 1; j <= l2; ++j)
                dp[0][j] = j;
            for(int i = 1; i <= l1; ++i)
                dp[i][0] = i;
            
            // dp[i][j] = edit distance between word1[0..i] and word2[0..j]
            // word1: a b c e f
            // word2: a b d h j
            // dp[2][2]
            // insert into word1:
            // a b d c e f => a b c e f
            // a b d h j => a b h j
            // 1 + dp[2][1]
            // delete from word1:
            // a b e f
            // a b d h j
            // 1 + dp[1][2]
            // replace
            // a b d e f
            // a b d h j
            for(int i = 1; i <= l1; ++i){
                for(int j = 1; j <= l2; ++j){
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else{
                        int M = INT_MAX;
                        // use insert, delete, or replace
                        M = min(M, dp[i][j-1]); // insert into word1
                        M = min(M, dp[i-1][j]); // delete from word1
                        M = min(M, dp[i-1][j-1]); // replace
                        dp[i][j] = M + 1;
                    }
                }
            }
            return dp[l1][l2];
        }
    };