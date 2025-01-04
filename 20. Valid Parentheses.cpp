class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto& c : s){
            if(c=='('||c=='['||c=='{')
                st.push(c);
            else{
                if(!st.empty()){
                    char top_c = st.top();
                    if(!((top_c=='('&&c==')')||(top_c=='['&&c==']')||(top_c=='{'&&c=='}')))
                        return false;
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
