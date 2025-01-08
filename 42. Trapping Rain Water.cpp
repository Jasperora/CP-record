class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==1) return 0;

        int max_left[height.size()];
        int max_right[height.size()];
        max_left[0] = max_right[height.size()-1] = 0;
        for(int i = 1; i < height.size()-1; ++i)
            max_left[i] = max(max_left[i-1], height[i-1]);
        // don't need max_right array, can keep only one value 
        // and simultaneously calculate max right in the final for loop
        for(int i = height.size()-2; i >= 0; --i)
            max_right[i] = max(max_right[i+1], height[i+1]);
        
        int ans = 0;
        for(int i = 1; i < height.size()-1; ++i)
            ans += max(min(max_left[i], max_right[i]) - height[i], 0);
        return ans;
    }
};
