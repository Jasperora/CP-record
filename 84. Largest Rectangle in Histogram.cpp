// monotonic stack
// 1 pass
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // because we calculate area when some element is popped out of stack
        // to ensure that something would be popped
        // add 0 at back
        heights.push_back(0);
        // to ensure that stack would have elements after popping
        // add 0 at begin
        heights.insert(heights.begin(), 0);
        stack<int> st;
        int ret = 0;
        for(int i = 0; i < n+2; ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                // nextSmaller is i
                // prevSmaller is st.top()
                st.pop();
                int area = h * (i - st.top() - 1);
                ret = max(ret, area);
            }
            st.push(i);
        }
        return ret;
    }
};
// monotonic stack
// 2 passes
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                nextSmaller[st.top()] = i;
                st.pop();
            }
            if(!st.empty())
                prevSmaller[i] = st.top();
            st.push(i);
        }
        int ret = 0;
        for(int i = 0; i < n; ++i){
            ret = max(ret, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return ret;
    }
};
// monotonic stack
// 3 passes
class Solution3 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // use monotonic stack to find the next smaller and previous smaller
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);
        stack<int> st1, st2;
        for(int i = 0; i < n; ++i){
            while(!st1.empty() && heights[i] < heights[st1.top()]){
                nextSmaller[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
        for(int i = n-1; i >= 0; --i){
            while(!st2.empty() && heights[i] < heights[st2.top()]){
                prevSmaller[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
        int ret = 0;
        for(int i = 0; i < n; ++i){
            ret = max(ret, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return ret;
    }
};