class Solution {
public:
    int maxScore(string s) {
        int one_cnt = 0;
        for(auto& c : s) one_cnt += (c=='1');
        int zero_cnt = s.size()-one_cnt;
        int left = 0, right = one_cnt;
        int ret= 0;
        for(int i = 0; i < s.size()-1; ++i){
            if(s[i]=='0') ++left;
            else --right;
            ret = max(ret, left+right);
        }
        return ret;
    }
};