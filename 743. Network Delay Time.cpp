class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int, int> > > adj(n+1);
            vector<bool> visited;
            for(auto& t : times){
                // dist, target
                adj[t[0]].push_back({t[2], t[1]});
            }
            visited.resize(n, false);
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;
            min_heap.push({0, k});
    
            int ret = 0;
            while(!min_heap.empty()){
                pair<int, int> p = min_heap.top();
                min_heap.pop();
                if(visited[p.second-1]) continue;
                ret = p.first;
                visited[p.second-1] = true;
                for(auto& pa : adj[p.second]){
                    int dist = pa.first;
                    int neighbor = pa.second;
                    if(!visited[neighbor-1])
                        min_heap.push({ret+dist, neighbor});
                }
            }
            for(int i = 0; i < n; ++i){
                if(!visited[i]) return -1;
            }
            return ret;
    
        }
    };
    