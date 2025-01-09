class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int> > s;
        vector<int> ret(temperatures.size(), 0);
        for(int i = temperatures.size()-1; i >= 0; --i){
            if(s.empty()){
                ret[i] = 0;
                pair<int, int> p(temperatures[i], i);
                s.push(p);
            }else{
                while(!s.empty() && temperatures[i]>=s.top().first){
                    s.pop();
                }
                if(s.empty()) ret[i] = 0;
                else ret[i] = s.top().second - i;
                pair<int, int> p(temperatures[i], i);
                s.push(p);
            }
        }
        return ret;
    }
};
