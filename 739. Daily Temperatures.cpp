class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> sp;
            vector<int> ret(temperatures.size());
            for(int i = temperatures.size()-1; i >= 0; --i){
                if(sp.empty()){
                    ret[i] = 0;
                    sp.push(i);
                }else{
                    if(temperatures[i]>=temperatures[sp.top()]){
                        while(!sp.empty()&&temperatures[i]>=temperatures[sp.top()]){
                            sp.pop();
                        }
                        if(sp.empty()) ret[i] = 0;
                        else ret[i] = sp.top() - i;
                        sp.push(i);
                    }else{
                        ret[i] = sp.top()- i;
                        sp.push(i);
                    }
                }
            }
            return ret;
        }
    };