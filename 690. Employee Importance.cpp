/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    public:
        int ret;
        unordered_set<int> visited;
        void dfs(const vector<Employee*>& employees, int id){
            if(visited.count(id)) return;
            visited.insert(id);
            for(int i = 0; i < employees.size(); ++i){
                if(employees[i]->id == id){
                    ret += employees[i]->importance;
                    for(auto& subordinate : employees[i]->subordinates){
                        dfs(employees, subordinate);
                    }
                    break;
                }
            }
        }
        int getImportance(vector<Employee*> employees, int id) {
            ret = 0;
            dfs(employees, id);
            return ret;
        }
    };