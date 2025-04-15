class Solution {
    public:
        vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
            int n = servers.size(), m = tasks.size();
            // weight, server index
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
            // {available time, {weight, server index}}
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> busy;
            for(int i = 0; i < n; ++i){
                available.push({servers[i], i});
            }
    
            vector<int> ret;
            int time = 0;
            for(int i = 0; i < m; ++i){
                time = max(time, i);
                // release machines from busy if they're done
                while(!busy.empty() && busy.top().first <= time){
                    auto [weight, server_index] = busy.top().second;
                    busy.pop();
                    available.push({weight, server_index});
                }
    
                // see if there are avaialable machines
                // if not
                if(available.empty()){
                    // fast forward to first available time
                    time = busy.top().first;
                    // check if there are other machines are done from busy
                    while(!busy.empty() && busy.top().first <= time){
                        auto [weight, server_index] = busy.top().second;
                        busy.pop();
                        available.push({weight, server_index});
                    }
                }
                // use available to do task i
                auto [weight, server_index] = available.top();
                available.pop();
                busy.push({time + tasks[i], {weight, server_index}});
                ret.push_back(server_index);
            }
            return ret;
        }
    };