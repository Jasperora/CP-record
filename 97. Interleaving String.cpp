class Solution {
private:
    vector<vector<bool> > dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l1+l2 != l3) return false;
        dp.resize(l1+1, vector<bool>(l2+1, false));
        dp[l1][l2] = true;
        
        for(int i = l1; i >= 0; --i){
            for(int j = l2; j >= 0; --j){
                if(i<l1 && s1[i]==s3[i+j] && dp[i+1][j])
                    dp[i][j] = true;
                if(j<l2 && s2[j]==s3[i+j] && dp[i][j+1])
                    dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};
