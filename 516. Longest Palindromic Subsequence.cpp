class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = "";
        // r is reversed s
        for(int i = 0; i < n; ++i)
            r.push_back(s[n-1-i]);
        // run LCS
        vector<int> cur(n+1, 0);
        vector<int> prev(n+1, 0);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(s[i-1] == r[j-1])
                    cur[j] = prev[j-1] + 1;
                else
                    cur[j] = max(prev[j], cur[j-1]);
            }
            swap(cur, prev);
        }
        return prev[n];
    }
};