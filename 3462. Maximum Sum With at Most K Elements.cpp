class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            vector<long long> B;
            for(int i = 0; i < grid.size(); ++i){
                sort(grid[i].rbegin(), grid[i].rend());
                for(int j = 0; j < limits[i]; ++j){
                    B.push_back(grid[i][j]);
                }
            }
            sort(B.rbegin(), B.rend());
            long long ret = 0;
            for(int i = 0; i < k; ++i) ret += B[i];
            return ret;
        }
    };