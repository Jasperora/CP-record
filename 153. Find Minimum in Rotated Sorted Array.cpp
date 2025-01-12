class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size()+1];
        for(int i = 0; i < s.size(); ++i) dp[i] = false;
        dp[s.size()] = true;
        for(int i = s.size()-1; i >= 0; --i){
            for(auto& word : wordDict){
                if(word.size()<=s.size()-i && s.substr(i, word.size())==word){
                    dp[i] |= dp[i+word.size()];
                }
            }
        }
        return dp[0];
    }
};
