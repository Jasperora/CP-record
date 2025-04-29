class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> prob(n, vector<double>(n, 0));
        prob[row][column] = 1;
        vector<pair<int, int>> dirs(8);
        dirs[0] = {-1, 2};
        dirs[1] = {-1, -2};
        dirs[2] = {-2, -1};
        dirs[3] = {-2, 1};
        dirs[4] = {1, 2};
        dirs[5] = {1, -2};
        dirs[6] = {2, 1};
        dirs[7] = {2, -1};
        while(k--){
            vector<vector<double>> new_prob(n, vector<double>(n, 0));
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(prob[i][j] == 0)
                        continue;
                    for(auto& dir: dirs){
                        int new_y = i + dir.first;
                        if(new_y < 0 || new_y >= n)
                            continue;
                        int new_x = j + dir.second;
                        if(new_x < 0 || new_x >= n)
                            continue;
                        
                        new_prob[new_y][new_x] += prob[i][j] / 8;
                    }
                }
            }
            swap(prob, new_prob);
        }
        double ret = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                ret += prob[i][j];
        }
        return ret;
    }
};