class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int start = -1, end = -1;
            int left = 0, right = nums.size() - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(nums[mid] > target){
                    right = mid - 1;
                }else if(nums[mid] < target){
                    left = mid + 1;
                }else{
                    start = mid;
                    right = mid - 1;
                }
            }
            left = 0;
            right = nums.size() - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(nums[mid] > target){
                    right = mid - 1;
                }else if(nums[mid] < target){
                    left = mid + 1;
                }else{
                    end = mid;
                    left = mid + 1;
                }
            }
            return {start, end};
        }
    };