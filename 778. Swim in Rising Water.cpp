class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            int n = grid.size();
            priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
            vector<vector<bool> > visited;
            visited.resize(n, vector<bool>(n, false));
    
            pq.push({grid[0][0], 0, 0});
            visited[0][0] = true;
            pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            while(!pq.empty()){
                // (time/max height, row, col)
                auto top = pq.top();
                pq.pop();
                int t = top[0], r = top[1], c = top[2];
    
                if(r==n-1 && c==n-1) return t;
                for(auto& dir : dirs){
                    int next_r = dir.first + r;
                    int next_c = dir.second + c;
                    if(0<=next_r && next_r<=n-1 && 0<=next_c && next_c<=n-1 && !visited[next_r][next_c]){
                        pq.push({max(top[0], grid[next_r][next_c]), next_r, next_c});
                        visited[next_r][next_c] = true;
                    }
                }
            }
            return 0;
        }
    };
    