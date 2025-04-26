class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ret = 0;
        int n = instructions.size();
        int i = 0;
        vector<bool> visited(n, false);
        while(i < n && i >= 0){
            if(visited[i]) break;
            visited[i] = true;
            if(instructions[i] == "add"){
                ret += values[i];
                ++i;
            }
            else i += values[i];
        }
        return ret;
    }
};