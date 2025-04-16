class Solution {
    public:
        vector<int> colors;
        bool dfs(const vector<vector<int>>& graph, int i, int color){
            // return false if a neighbor has same color as it
            colors[i] = color;
            for(auto& neighbor : graph[i]){
                if(colors[neighbor] == color) return false;
                // paint neighbor to another color
                if(colors[neighbor] == 0){
                    if(!dfs(graph, neighbor, 3 - color))
                        return false;
                }
            }
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            // 0: unvisited, 1: red, 2: blue
            colors.resize(n, 0);
            for(int i = 0; i < n; ++i){
                if(colors[i] == 0){
                    // paint it red
                    if(!dfs(graph, i, 1))
                        return false;
                }
            }
            return true;
        }
    };