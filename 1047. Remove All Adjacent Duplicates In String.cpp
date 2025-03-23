class Solution {
    public:
        string removeDuplicates(string s) {
            stack<char> sc;
            for(auto& c : s){
                if(sc.empty()) sc.push(c);
                else{
                    if(c==sc.top())
                        sc.pop();
                    else sc.push(c);
                }
            }
            string ret = "";
            while(!sc.empty()){
                ret.push_back(sc.top());
                sc.pop();
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
    };