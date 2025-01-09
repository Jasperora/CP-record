class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, ret = 0;
        map<char, int> m;
        while(right<s.length()){
            if(!m.count(s[right]))
                m[s[right]] = 0;
            ++m[s[right]];
            int max_freq = 0;
            for(auto& p : m){
                if(p.second>max_freq)
                    max_freq = p.second;
            }
            if(right-left+1-max_freq<=k)
                ret = max(right-left+1, ret);
            else{
                --m[s[left]];
                ++left;
            }
            ++right;
        }
        return ret;
    }
};
