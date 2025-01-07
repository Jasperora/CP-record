class Solution {
public:
    static bool cmp(string a, string b){
        if(a.size()!=b.size()) return a.size() < b.size();
        else return a < b;
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.rbegin(), words.rend(), cmp);
        vector<string> ans;
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(words[j].find(words[i])!=string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};