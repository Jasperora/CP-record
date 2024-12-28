class Solution {
public:
    int maxArea(vector<int>& heights) {
        int a = 0, b = heights.size()-1;
        int max = -1;
        while(b!=a){
            int area = (b-a) * min(heights[a], heights[b]);
            if(area>max) max = area;
            if(heights[a]<heights[b]) ++a;
            else --b;
        }
        return max;
    }
};