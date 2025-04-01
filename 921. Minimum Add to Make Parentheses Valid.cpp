class Solution {
    public:
        int minAddToMakeValid(string s) {
            stack<char> sc;
            for(auto& c : s){
                if(sc.empty()){
                    sc.push(c);
                }else{
                    if(c==')' && sc.top()=='(')
                        sc.pop();
                    else
                        sc.push(c);
                }
            }
            return sc.size();
        }
    };