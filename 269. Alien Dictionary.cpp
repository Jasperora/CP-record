class Solution {
    private:
        unordered_map<char, bool> visited;
        unordered_map<char, unordered_set<char>> adj;
        string ret;
        bool dfs(char c){
            if(visited.count(c)){
                return visited[c];
            }
            visited[c] = true;
            for(auto& next : adj[c]){
                if(dfs(next)) return true;
            }
            visited[c] = false;
            ret.push_back(c);
            return false;
        }
    public:
        string foreignDictionary(vector<string>& words) {
            for(auto& word : words){
                for(auto& c : word){
                    adj[c];
                }
            }
    
            for(int i = 0; i < words.size()-1; ++i){
                string& w1 = words[i];
                string& w2 = words[i+1];
                int min_len = min(w1.size(), w2.size());
                if(w1.size()>w2.size() && w1.substr(0, min_len)==w2.substr(0, min_len)){
                    return "";
                }
                for(int j = 0; j < min_len; ++j){
                    if(w1[j]!=w2[j]){
                        adj[w1[j]].insert(w2[j]);
                        break;
                    }
                }
            }
    
            for(auto& p : adj){
                if(dfs(p.first)) return "";
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
    };
    