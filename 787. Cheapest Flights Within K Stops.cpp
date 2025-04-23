class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            // relax all edges by k + 1 times
            for(int i = 0; i < k + 1; ++i){
                // for not relax too much
                vector<int> tmp_dist(dist.begin(), dist.end());
                for(auto& flight : flights){
                    int from = flight[0], to = flight[1], price = flight[2];
                    // or it will overflow
                    if(dist[from] == INT_MAX) continue;
                    // use tmp_dist to store dist
                    // but use dist to calculate new_dist
                    int new_dist = dist[from] + price;
                    if(tmp_dist[to] > new_dist)
                        tmp_dist[to] = new_dist;
                }
                for(int i = 0; i < n; ++i)
                    dist[i] = tmp_dist[i];
            }
    
            return (dist[dst] == INT_MAX) ? -1 : dist[dst];
        }
    };