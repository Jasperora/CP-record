class Solution {
public:
    string RLE(string s){
        string ret = "";
        char c = s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i]==c){
                ++cnt;
            }else{
                ret += to_string(cnt);
                ret.push_back(c);
                c = s[i];
                cnt = 1;
            }
        }
        ret += to_string(cnt);
        ret.push_back(c);
        return ret;
    }
    string countAndSay(int n) {
        string ret = "1";
        for(int i = 1; i < n; ++i){
            ret = RLE(ret);
        }
        return ret;
    }
};