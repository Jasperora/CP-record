class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for(auto& word : words){
            bool has_prefix = true;
            for(int i = 0; i < pref.length(); ++i){
                if(word[i]!=pref[i]){
                    has_prefix = false;
                    break;
                }
            }
            ret += has_prefix;
        }
        return ret;
    }
};