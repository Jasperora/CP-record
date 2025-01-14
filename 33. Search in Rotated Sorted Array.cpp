class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) return nums[0]==target ? 0 : -1;

        int left = 0, right = nums.size()-1;
        if(nums[left]>=nums[right]){
            // find transition point first
            while(left!=right-1){
                int mid = (left+right)>>1;
                if(nums[mid]>=nums[left]){
                    left = mid;
                }else if(nums[mid]<=nums[right]){
                    right = mid;
                }
            }
            if(target>=nums[0]){
                right = left;
                left = 0;
            }else if(target<=nums[nums.size()-1]){
                left = right;
                right = nums.size()-1;
            }
        }else{
            left = 0;
            right = nums.size()-1;
        }
        // binary search target
        while(left!=right-1&&left!=right){
            int mid = (left+right)>>1;
            if(nums[mid]>target){
                right = mid;
            }else if(nums[mid]<target){
                left = mid;
            }else return mid;
        }
        if(nums[left]==target) return left;
        if(nums[right]==target) return right;
        return -1;
    }
};
