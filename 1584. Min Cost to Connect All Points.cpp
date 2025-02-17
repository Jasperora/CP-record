class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            int n = points.size();
            int adj[n][n];
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(i==j) continue;
                    adj[i][j] = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                }
            }
            bool visited[n];
            fill(visited, visited+n, false);
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;
            min_heap.push({0, 0});
            bool done = false;
            int ret = 0;
            while(!done){
                // dist, node
                pair<int, int> p = min_heap.top();
                min_heap.pop();
                // cout << p.first << ' ' << p.second << '\n';
                if(!visited[p.second]){
                    ret += p.first;
                    visited[p.second] = true;
                    for(int i = 0; i < n; ++i){
                        if(!visited[i]) min_heap.push({adj[p.second][i], i});
                    }
                }
                done = true;
                for(int i = 0; i < n; ++i) done &= visited[i];
                if(done) break;
            }
            return ret;
        }
    };
    