class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int left = 0, right = nums.size() - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(mid+1 < nums.size() && nums[mid] < nums[mid+1]){
                    left = mid + 1;
                }else if(mid-1 >= 0 && nums[mid-1] > nums[mid]){
                    right = mid - 1;
                }else{
                    return mid;
                }
            }
            return left;
        }
    };