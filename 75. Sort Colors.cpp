class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int left = 0, mid = 0, right = nums.size() - 1;
            while(mid <= right){
                if(nums[mid] == 0){
                    swap(nums[left], nums[mid]);
                    ++left;
                    ++mid;
                }else if(nums[mid] == 1){
                    ++mid;
                }else{
                    // can't ++mid here
                    // because if after swapping, nums[right] == 0
                    // ++mid will not put it to right place
                    swap(nums[mid], nums[right]);
                    --right;
                }
            }
        }
    };