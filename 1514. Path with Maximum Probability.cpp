// Dijkstra's algorithm
class Solution1 {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> maxHeap;
        vector<double> probs(n, 0);
        // prob, node
        maxHeap.push({1, start_node});
        while(!maxHeap.empty()){
            auto [prob, node] = maxHeap.top();
            if(node == end_node) return prob;
            maxHeap.pop();
            for(auto& [neighbor, p] : adj[node]){
                if(probs[neighbor] < prob * p){
                    probs[neighbor] = prob * p;
                    maxHeap.push({probs[neighbor], neighbor});
                }
            }
        }
        return 0;
    }
};
// Bellman-Ford algorithm
// TLE
class Solution2 {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        for(int i = 0; i < n-1; ++i){
            // relax all edges n-1 times
            for(int u = 0; u < n; ++u){
                for(const auto& [v, p] : adj[u]){
                    double new_prob = prob[u] * p;
                    if(prob[v] < new_prob)
                        prob[v] = new_prob;
                }
            }
        }
        return prob[end_node];
    }
};