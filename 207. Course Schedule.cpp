class Solution {
private:
    set<int> visited;
    vector<vector<int> > pre;
public:
    bool dfs(int root){
        if(visited.count(root)) return false;
        if(pre[root].empty()) return true;
        visited.insert(root);
        for(auto& course : pre[root]){
            if(!dfs(course)) return false;
        }
        // to save time
        pre[root].clear();
        // because it will use different course as start
        // erase visited is necessary
        visited.erase(root);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        pre.resize(numCourses);
        for(auto& p : prerequisites){
            pre[p[0]].push_back(p[1]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i)) return false;
        }
        return true;
    }
};
