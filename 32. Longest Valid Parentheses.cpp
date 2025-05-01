class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                st.push(i);
            else{
                // thing remaining in stack would become a wall
                // to separate value and invalid parentheses
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                    if(st.empty())
                        ret = max(ret, i + 1);
                    else
                        ret = max(ret, i - st.top());
                }else{
                    st.push(i);
                }
            }
        }
        return ret;
    }
};