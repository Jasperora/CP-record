class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's algorithm
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto& pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
            ++inDegree[pair[0]];
        }
        queue<int> zero_queue;
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0)
                zero_queue.push(i);
        }
        vector<int> ret;
        while(!zero_queue.empty()){
            int front = zero_queue.front();
            ret.push_back(front);
            zero_queue.pop();
            for(auto& neighbor : adj[front]){
                --inDegree[neighbor];
                if(inDegree[neighbor] == 0)
                    zero_queue.push(neighbor);
            }
        }
        return ret.size() == numCourses ? ret : vector<int>{};

    }
};
class Solution2 {
public:
    bool has_cycle;
    stack<int> order;
    vector<vector<int>> adj;
    // 0: unvisited, 1: visiting, 2: visited
    vector<int> status;
    void dfs(int i){
        if(has_cycle) return;
        status[i] = 1;
        for(auto& neighbor : adj[i]){
            if(status[neighbor] == 1){
                has_cycle = true;
                return;
            }else if(status[neighbor] == 0){
                dfs(neighbor);
            }
        }
        order.push(i);
        status[i] = 2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        status.resize(numCourses, 0);
        for(auto & pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
        }
        has_cycle = false;
        for(int i = 0; i < numCourses; ++i){
            if(status[i] == 0){
                dfs(i);
                if(has_cycle) return {};
            }
        }
        vector<int> ret;
        while(!order.empty()){
            ret.push_back(order.top());
            order.pop();
        }
        return ret;
    }
};