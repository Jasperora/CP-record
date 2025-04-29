class Solution {
public:
    long long squareDist(const vector<int>& p1, const vector<int>& p2){
        long long x_diff = p1[0] - p2[0];
        long long y_diff = p1[1] - p2[1];
        return x_diff*x_diff + y_diff*y_diff;
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        double ret = DBL_MAX;
        int n = points.size();
        
        unordered_map<string, vector<pair<int, int>>> m;
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                // two pairs of diagonal would have same sum of x, sum of y, and distance
                int sum_x = points[i][0] + points[j][0];
                int sum_y = points[i][1] + points[j][1];
                int d = squareDist(points[i], points[j]);
                string s = to_string(sum_x) + "-" + to_string(sum_y) + "-" + to_string(d);
                if(m.count(s)){
                    for(auto& [pi, pj]: m[s]){
                        ret = min(ret, sqrt(squareDist(points[i], points[pi])) * sqrt(squareDist(points[j], points[pi])));
                    }
                }
                m[s].push_back({i, j});
            }
        }
        return ret == DBL_MAX ? 0 : ret;
    }
};