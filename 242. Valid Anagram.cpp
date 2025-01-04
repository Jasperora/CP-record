class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_char_cnt, t_char_cnt;
        for(int i = 0; i < 26; ++i){
            s_char_cnt['a'+i] = t_char_cnt['a'+i] = 0;
        }
        for(auto& c : s) ++s_char_cnt[c];
        for(auto& c : t) ++t_char_cnt[c];
        bool ans = true;
        for(int i = 0; i < 26; ++i){
            ans &= (s_char_cnt['a'+i]==t_char_cnt['a'+i]);
        }
        return ans;
    }
};