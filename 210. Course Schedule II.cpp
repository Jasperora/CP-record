class Solution {
private:
    set<int> visit, cycle;
    map<int, vector<int> > adj;
    vector<int> ret;
    bool dfs(int course){
        if(cycle.count(course)) return false;
        if(visit.count(course)) return true;

        cycle.insert(course);
        for(auto& c : adj[course]){
            if(!dfs(c)) return false;
        }
        cycle.erase(course);
        visit.insert(course);
        ret.push_back(course);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        for(auto& p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        bool no_cycle = true;
        for(int i = 0; i < numCourses; ++i){
            no_cycle &= dfs(i);
        }
        if(no_cycle)
            return ret;
        else{
            vector<int> empty;
            return empty;
        }
    }
};
