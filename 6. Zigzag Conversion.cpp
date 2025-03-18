class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows==1) return s;
            vector<string> vs(numRows);
            int d = 1, cur = 0;
            for(int i = 0; i < s.size(); ++i){
                vs[cur].push_back(s[i]);
                if(cur==numRows-1){
                    d = -1;
                }
                if(cur==0){
                    d = 1;
                }
                cur += d;
            }
            string ret = "";
            for(int i = 0; i < numRows; ++i){
                ret += vs[i];
            }
            return ret;
        }
    };