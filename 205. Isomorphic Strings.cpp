class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char, vector<int>> m1, m2;
            for(int i = 0; i < s.size(); ++i){
                m1[s[i]].push_back(i);
            }
            for(int i = 0; i < t.size(); ++i){
                m2[t[i]].push_back(i);
            }
            vector<vector<int>> vv1, vv2;
            for(auto& p : m1){
                vv1.push_back(p.second);
            }
            for(auto& p : m2){
                vv2.push_back(p.second);
            }
            sort(vv1.begin(), vv1.end());
            sort(vv2.begin(), vv2.end());
            return vv1==vv2;
        }
    };