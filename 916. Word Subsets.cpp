class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<int, int> m2, tmp;
        for(int i = 0; i < 26; ++i){
            m2[i] = tmp[i] = 0;
        }
        for(auto& word : words2){
            for(auto& c : word){
                ++tmp[c-'a'];
            }
            for(int i = 0; i < 26; ++i){
                m2[i] = max(tmp[i], m2[i]);
                tmp[i] = 0;
            }
        }
        vector<string> ret;
        for(auto& word : words1){
            for(auto& c : word){
                ++tmp[c-'a'];
            }
            bool is_universal = true;
            for(int i = 0; i < 26; ++i){
                is_universal &= (tmp[i] >= m2[i]);
                tmp[i] = 0;
            }
            if(is_universal) ret.push_back(word);
        }
        return ret;
    }
};