class Solution {
    public:
        bool equal(unordered_map<int, int>& a, unordered_map<int, int>& b){
            for(int i = 0; i < 26; ++i){
                if(a[i]!=b[i])
                    return false;
            }
            return true;
        }
        vector<int> findAnagrams(string s, string p) {
            if(s.size()<p.size()) return {};
            unordered_map<int, int> ms, mp;
            for(int i = 0; i < 26; ++i){
                ms[i] = mp[i] = 0;
            }
            for(auto& c : p) mp[c-'a']++;
            for(int i = 0; i < p.size(); ++i) ms[s[i]-'a']++;
            vector<int> ret;
            int diff = s.size() - p.size();
            for(int i = 0; i < diff; ++i){
                if(equal(ms, mp)) ret.push_back(i);
                ms[s[i]-'a']--;
                ms[s[i+p.size()]-'a']++;
            }
            if(equal(ms, mp)) ret.push_back(diff);
            return ret;
        }
    };