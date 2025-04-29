class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        for(auto& point : points){
            m[point[0]].insert(point[1]);
        }
        int n = points.size();
        int ret = INT_MAX;
        for(int i = 0; i < n - 1; ++i){
            for(int j = 1; j < n; ++j){
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                    if(m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1]))
                        ret = min(ret, abs(points[j][1]-points[i][1])*abs(points[j][0]-points[i][0]));
                }
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};