class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            queue<string> q;
            unordered_set<string> visited;
            for(int i = 0; i < deadends.size(); ++i){
                if(deadends[i] == "0000")
                    return -1;
                // cannot go to deadend
                visited.insert(deadends[i]);
            }
            q.push("0000");
            visited.insert("0000");
            int distance = 0;
            while(!q.empty()){
                int len = q.size();
                for(int i = 0; i < len; ++i){
                    string front = q.front();
                    if(front == target)
                        return distance;
                    q.pop();
                    for(int j = 0; j < 4; ++j){
                        string next1 = front, next2 = front;
                        next1[j] = (next1[j] - '0' + 1) % 10 + '0';
                        next2[j] = (next2[j] - '0' + 9) % 10 + '0';
                        if(!visited.count(next1)){
                            q.push(next1);
                            visited.insert(next1);
                        }
                        if(!visited.count(next2)){
                            q.push(next2);
                            visited.insert(next2);
                        }
                    }
                }
                ++distance;
            }
            return -1;
        }
    };