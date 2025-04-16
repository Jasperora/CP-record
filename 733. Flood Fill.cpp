class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            queue<pair<int, int>> q;
            int m = image.size();
            int n = image[0].size();
            int original_color = image[sr][sc];
            image[sr][sc] = color;
            q.push({sr, sc});
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[sr][sc] = true;
            while(!q.empty()){
                auto front = q.front();
                image[front.first][front.second] = color;
                visited[front.first][front.second] = true;
                q.pop();
                if(front.first - 1 >= 0 && image[front.first - 1][front.second] == original_color && !visited[front.first - 1][front.second]){
                    q.push({front.first - 1, front.second});
                }
                if(front.first + 1 < m && image[front.first + 1][front.second] == original_color && !visited[front.first + 1][front.second])
                    q.push({front.first + 1, front.second});
                if(front.second - 1 >= 0 && image[front.first][front.second - 1] == original_color && !visited[front.first][front.second - 1])
                    q.push({front.first, front.second - 1});
                if(front.second + 1 >= 0 && image[front.first][front.second + 1] == original_color && !visited[front.first][front.second + 1])
                    q.push({front.first, front.second + 1});
            }
            return image;
        }
    };