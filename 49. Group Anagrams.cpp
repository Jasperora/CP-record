class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<char, int> char_cnt[strs.size()];
        map<map<char, int>, vector<string> > anagrams;
        for(int i = 0; i < strs.size(); ++i){
            for(auto& c : strs[i]){
                if(!char_cnt[i].count(c)) char_cnt[i][c] = 0;
                ++char_cnt[i][c];
            }
            anagrams[char_cnt[i]].push_back(strs[i]);
        }
        vector<vector<string> > ans;
        for(auto& p : anagrams){
            ans.push_back(p.second);
        }
        return ans;
    }
};
