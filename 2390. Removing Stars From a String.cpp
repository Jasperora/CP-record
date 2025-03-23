class Solution {
    public:
        string removeStars(string s) {
            string ret = "";
            for(auto& c : s){
                if(c=='*'&&!ret.empty()) ret.pop_back();
                else if(c!='*') ret.push_back(c);
            }
            return ret;
        }
    };