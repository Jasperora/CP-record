class Solution {
public:
    map<int, int> dp;
    int dfs(const int& i, const string& s){
        if(dp.count(i)) return dp[i];
        else{
            dp[i] = 0;
            if(s[i]!='0'){
                dp[i] += dfs(i+1, s);
                if(i<s.size()-1&&((s[i]=='1')||(s[i]=='2'&&s[i+1]<='6')))
                    dp[i] += dfs(i+2, s);
            }
            return dp[i];
        }
    }
    int numDecodings(string s) {
        dp[s.size()] = 1;
        dfs(0, s);
        return dp[0];
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        int dp[s.size()+1];
        dp[s.size()] = 1;
        for(int i = s.size()-1; i >= 0; --i){
            if(s[i]=='0') dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if(i<s.size()-1&&((s[i]=='1')||(s[i]=='2'&&s[i+1]>='0'&&s[i+1]<='6')))
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
