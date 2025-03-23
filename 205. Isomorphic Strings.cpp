class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.size()!=t.size()) return false;
            unordered_map<char, vector<int>> m1, m2;
            for(int i = 0; i < s.size(); ++i){
                m1[s[i]].push_back(i);
                m2[t[i]].push_back(i);
            }
            vector<vector<int>> v1, v2;
            for(auto& p : m1) v1.push_back(p.second);
            for(auto& p : m2) v2.push_back(p.second);
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            return v1==v2;
        }
    };