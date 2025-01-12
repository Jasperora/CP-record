class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        if(nums[left]<=nums[right]) return nums[left];
        while(right!=left+1){
            int mid = (left+right)>>1;
            if(nums[mid]>nums[left]){
                left = mid;
            }else if(nums[mid]<nums[right]){
                right = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};
