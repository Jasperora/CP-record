class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ret(n);
        for(int i = n-1; i >= 0; --i){
            int cnt = 0;
            while(!st.empty() && st.top() < heights[i]){
                // count how many people are shorter than person i
                st.pop();
                ++cnt;
            }
            if(!st.empty()){
                // the top of the stack is higher than person i
                ret[i] = cnt + 1;
            }else{
                ret[i] = cnt;
            }
            st.push(heights[i]);
        }
        return ret;
    }
};