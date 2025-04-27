class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> cur(n), next(n);
        for(int i = 0; i < n; ++i)
            cur[i] = points[0][i];

        for(int i = 1; i < m; ++i){
            vector<long long> left(n, 0), right(n, 0);
            left[0] = cur[0];
            for(int j = 1; j < n; ++j){
                left[j] = max(cur[j], left[j-1]-1);
            }
            right[n-1] = cur[n-1];
            for(int j = n-2; j >= 0; --j){
                right[j] = max(cur[j], right[j+1]-1);
            }
            for(int j = 0; j < n; ++j){
                next[j] = points[i][j] + max(left[j], right[j]);
            }
            swap(cur, next);
        }
        return *max_element(cur.begin(), cur.end());
    }
};