class Solution {
    public:
        int characterReplacement(string s, int k) {
            vector<int> freq(26, 0);
            int start = 0;
            int ret = 0;
            int max_freq = 0;
    
            for(int end = 0; end < s.size(); ++end){
                max_freq = max(max_freq, ++freq[s[end]-'A']);
                if(end-start+1-max_freq > k){
                    --freq[s[start]-'A'];
                    ++start;
                }
                ret = max(ret, end-start+1);
            }
            return ret;
        }
    };