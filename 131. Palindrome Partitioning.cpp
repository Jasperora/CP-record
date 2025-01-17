class Solution {
public:
    vector<vector<string> > ret;
    vector<string> p;
    bool isPalindrome(int l, int r, const string& s){
        if(l==r) return true;
        while(l<r){
            if(s[l]!=s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
    void dfs(int idx, const string& s){
        if(idx>=s.size()) ret.push_back(p);
        else{
            for(int j = idx; j < s.size(); ++j){
                if(isPalindrome(idx, j, s)){
                    p.push_back(s.substr(idx, j-idx+1));
                    dfs(j+1, s);
                    p.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ret;
    }
};
