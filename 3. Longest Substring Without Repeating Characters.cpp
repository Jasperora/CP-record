class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> m;
            int ret = 0, tmp = 0;
            int start = 0;
            for(int i = 0; i < s.size(); ++i){
                if(m.count(s[i])){
                    start = max(start, m[s[i]]);
                    tmp = i - start;
                }else{
                    ++tmp;
                }
                ret = max(ret, tmp);
                m[s[i]] = i;
            }
            return ret;
        }
    };
    