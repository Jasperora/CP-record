class Solution {
    public:
        string frequencySort(string s) {
            vector<pair<int, int>> v;
            unordered_map<char, int> m;
            for(auto& c : s){
                ++m[c];
            }
            priority_queue<pair<int, char>> pq;
            for(auto& p : m){
                pq.push({p.second, p.first});
            }
            string ret = "";
            while(!pq.empty()){
                int times = pq.top().first;
                char c = pq.top().second;
                pq.pop();
                ret.append(times, c);
            }
            return ret;
        }
    };