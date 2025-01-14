class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size(), n = matrix[0].size();
        bool visited[m][n];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                visited[i][j] = false;
        }

        pair<int, int> cur(0, 0);
        bool done = false;
        int dir = 1;
        while(!done){
            if(!visited[cur.first][cur.second]){
                ret.push_back(matrix[cur.first][cur.second]);
                visited[cur.first][cur.second] = true;
            }
            switch(dir){
                default:
                    dir = 1;
                    break;
                case 1: // right
                    if(cur.second==n-1||visited[cur.first][cur.second+1])
                        dir = 2;
                    else ++cur.second;
                    break;
                case 2: // down
                    if(cur.first==m-1||visited[cur.first+1][cur.second])
                        dir = 3;
                    else ++cur.first;
                    break;
                case 3: // left
                    if(cur.second==0||visited[cur.first][cur.second-1])
                        dir = 4;
                    else --cur.second;
                    break;
                case 4: // up
                    if(cur.first==0||visited[cur.first-1][cur.second])
                        dir = 1;
                    else --cur.first;
                    break;
            }

            done = true;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(!visited[i][j]){
                        done = false;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};