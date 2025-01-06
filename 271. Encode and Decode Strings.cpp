class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); ++i){
            s += to_string(strs[i].size());
            s += ":";
            s += strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str = "";
        int i=0, j=0, l;
        while(i<s.length()){
            if(s[j]!=':') ++j;
            else{
                l = stoi(s.substr(i, j-i));
                ans.push_back(s.substr(j+1, l));
                j += l + 1;
                i = j;
            }
        }
        return ans;
    }
};
