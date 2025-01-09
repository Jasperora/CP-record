class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        set<char> sc;
        sc.insert(s[0]);
        int start = 0, end = 0, ret = 1;
        while(end<s.length()-1){
            ret = max(ret, end-start+1);
            if(!sc.count(s[end+1])){
                ++end;
                sc.insert(s[end]);
            }
            else{
                while(sc.count(s[end+1])){
                    sc.erase(s[start]);
                    ++start;
                }
                ++end;
                sc.insert(s[end]);
            }
        }
        ret = max(ret, end-start+1);
        return ret;
    }
};
