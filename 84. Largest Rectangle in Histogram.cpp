class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int> > s;
        int ret = 0;
        for(int i = 0; i < heights.size(); ++i){
            if(s.empty()){
                pair<int, int> p(heights[i], i);
                s.push(p);
            }else{
                pair<int, int> p;
                p.first = heights[i];
                p.second = i;
                while(!s.empty() && heights[i]<s.top().first){
                    ret = max(ret, s.top().first*(i-s.top().second));
                    p.second = s.top().second;
                    s.pop();
                }
                if(!s.empty()&&heights[i]==s.top().first){
                    ret = max(ret, s.top().first*(i-s.top().second+1));
                }else{
                    s.push(p);
                }
            }
        }
        while(!s.empty()){
            if(s.top().first*(heights.size()-s.top().second) > ret)
                ret = s.top().first*(heights.size()-s.top().second);
            s.pop();
        }
        return ret;
    }
};
