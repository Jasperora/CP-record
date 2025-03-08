class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> maxLeft(len, 0);
        for(int i = 1; i < len; ++i){
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        int ret = 0;
        int maxRight = 0;
        for(int i = len-2; i >= 0; --i){
            maxRight = max(maxRight, height[i+1]);
            ret += max(0, min(maxLeft[i], maxRight)-height[i]);
        }
        return ret;
    }
};
    