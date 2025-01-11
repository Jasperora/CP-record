class Solution {
public:
    vector<string> ret;
    string s = "";
    void search(int open, int close, int& n){
        if(s.size()==2*n){
            ret.push_back(s);
        }else{
            if(open < n){
                s.push_back('(');
                search(open+1, close, n);
                s.pop_back();
            }
            if(close < open){
                s.push_back(')');
                search(open, close+1, n);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        search(0, 0, n);
        return ret;
    }
};
