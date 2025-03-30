class Solution {
    public:
        int count(const string& s, int i, int j){
            int ret = 0;
            while(i>=0&&j<s.size()&&s[i]==s[j]){
                --i;
                ++j;
            }
            return j-i-1;
        }
        int longestPalindrome(string s, string t) {
            int mx = INT_MIN;
    
            string sub_s = "", sub_t = "";
            for(int i = 0; i < s.size(); ++i){
                for(int j = i+1; j <= s.size(); ++j){
                    sub_s = s.substr(i, j-i);
                    for(int k = 0; k < t.size(); ++k){
                        for(int l = k+1; l <= t.size(); ++l){
                            sub_t = t.substr(k, l-k);
                            string tmp = sub_s + sub_t;
                            for(int m = 0; m < tmp.size(); ++m){
                                mx = max(mx, count(tmp, m, m));
                                if(m+1<tmp.size()) mx = max(mx, count(tmp, m, m+1));
                            }
                        }
                    }
                }
            }
            return mx;
        }
    };