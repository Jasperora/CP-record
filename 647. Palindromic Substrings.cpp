class Solution {
public:
    vector<vector<bool> > dp;
    void checkPalindrome(const string& s, int left, int right){
        while((left>=0&&right<s.size()) && (dp[left][right]||s[left]==s[right])){
            dp[left][right] = true;
            --left;
            ++right;
        }
    }
    int countSubstrings(string s) {
        dp.resize(s.size(), vector<bool>(s.size(), false));
        // for(int i = 0; i < s.size(); ++i){
        //     dp[i][i] = true;
        // }
        for(int i = 0; i < s.size(); ++i){
            checkPalindrome(s, i, i);
            if(i!=s.size()-1)
                checkPalindrome(s, i, i+1);
        }

        int ret = 0;
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < s.size(); ++j){
                ret += dp[i][j];
            }
        }
        return ret;
    }
};
