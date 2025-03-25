class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string, int> m;
            for(auto& w : words)
                ++m[w];
            vector<pair<string, int>> v;
            for(auto& p : m){
                v.push_back({p.first, p.second});
            }
            sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b){  
                if(a.second!=b.second) return a.second > b.second;
                return a.first < b.first;
            });
            vector<string> ret;
            for(int i = 0; i < k; ++i)
                ret.push_back(v[i].first);
            return ret;
        }
    };