class Solution {
    public:
        string reorganizeString(string s) {
            map<char, int> m;
            vector<pair<int, int>> freq(26);
            for(int i = 0; i < 26; ++i) freq[i].first = i;
            for(auto& c : s) ++freq[c-'a'].second;
            sort(freq.rbegin(), freq.rend(), [](pair<int, int>& a, pair<int, int>& b){
                return a.second < b.second;
            });
            int sum = s.size();
            int limit = (int)ceil((float)sum/2)+1;
            if(freq[0].second>=limit) return "";
    
            vector<char> v(s.size());
            int idx = 0;
            for(int i = 0; i < sum; i += 2){
                v[i] = char(freq[idx].first+'a');
                --freq[idx].second;
                if(freq[idx].second==0) ++idx;
            }
            for(int i = 1; i < sum; i += 2){
                v[i] = char(freq[idx].first+'a');
                --freq[idx].second;
                if(freq[idx].second==0) ++idx;
            }
            string ret(v.begin(), v.end());
            return ret;
        }
    };