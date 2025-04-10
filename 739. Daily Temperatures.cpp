class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> s;
            int n = temperatures.size();
            vector<int> ret(n);
            for(int i = n-1; i >= 0; --i){
                while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                    s.pop();
                }
                if(s.empty()) ret[i] = 0;
                else ret[i] = s.top() - i;
                s.push(i);
            }
            return ret;
        }
    };