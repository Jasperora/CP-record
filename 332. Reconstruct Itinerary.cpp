// DFS
class Solution {
private:
    map<string, vector<string> > adj;
    vector<string> ret;
    int ans_len;
    bool dfs(const string& src){
        if(ret.size()==ans_len) return true;
        if(!adj.count(src)) return false;

        vector<string> destinations = adj[src];
        for(int i = 0; i < adj[src].size(); ++i){
            string dest = destinations[i];
            adj[src].erase(adj[src].begin()+i);
            ret.push_back(dest);
            if(dfs(dest)) return true;
            adj[src].insert(adj[src].begin()+i, dest);
            ret.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans_len = tickets.size() + 1;

        // map will implicitly be sorted
        // for lexicographic order
        for(auto& t : tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& p : adj){
            sort(p.second.begin(), p.second.end());
        }
        
        ret.push_back("JFK");
        dfs("JFK");
        return ret;
    }
};
// Heirholzer's algorithm
class Solution {
private:
    unordered_map<string, deque<string> > adj;
    vector<string> ret;
    void dfs(const string& src){
        while(!adj[src].empty()){
            string dest = adj[src].back();
            adj[src].pop_back();
            dfs(dest);
        }
        ret.push_back(src);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // for lexicographic order
        for(auto& t : tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& p : adj){
            sort(p.second.rbegin(), p.second.rend());
        }
        dfs("JFK");
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
    