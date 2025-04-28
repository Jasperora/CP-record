#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int M = 1e9 + 7;
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap;
        minHeap.push({0, 0});
        // build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        while(!minHeap.empty()){
            auto [cur_dist, u] = minHeap.top();
            minHeap.pop();
            // might be added first
            // but find a more efficient way later on
            if(cur_dist > dist[u]) continue;

            for(const auto& [v, distance]: adj[u]){
                ll new_dist = dist[u] + distance;
                if(new_dist < dist[v]){
                    dist[v] = new_dist;
                    ways[v] = ways[u];
                    minHeap.push({new_dist, v});
                }else if(new_dist == dist[v]){
                    ways[v] += ways[u] % M;
                    ways[v] %= M;
                }
            }
        }
        return ways[n-1];
    }
};