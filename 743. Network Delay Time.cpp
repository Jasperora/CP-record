// Bellman-Ford algorithm
// can be used with graphs with negative cycles
class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n, INT_MAX);
        distance[k-1] = 0;
        for(int i = 0; i < n-1; ++i){
            // relax all edges for n-1 times
            for(auto& time : times){
                if(distance[time[0]-1] != INT_MAX && distance[time[0]-1] + time[2] < distance[time[1]-1])
                    distance[time[1]-1] = distance[time[0]-1] + time[2];
            }
        }
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(distance[i] == INT_MAX){
                // can't reach
                return -1;
            }else{
                // find the point that takes most time to reach
                ret = max(ret, distance[i]);
            }
        }
        return ret;
    }
};
// Dijkstra algorithm
// cannot be used with graphs with negative edges
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dist, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[k - 1] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for(auto& edge : times){
            // dest, time
            adj[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        }

        // start from k
        minHeap.push({0, k - 1});
        while(!minHeap.empty()){
            auto [d, node] = minHeap.top();
            minHeap.pop();
            if(visited[node]) continue;
            visited[node] = true;
            for(auto& [dest, time] : adj[node]){
                // relax if dist can be decreased
                if(d + time < dist[dest]){
                    dist[dest] = d + time;
                    minHeap.push({dist[dest], dest});
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(dist[i] == INT_MAX)
                return -1;
            ret = max(ret, dist[i]);
        }
        return ret;
    }
};