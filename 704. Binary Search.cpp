class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        int low=0, high=nums.size()-1;
        while(true){
            if(nums[low]==target) return low;
            if(nums[high]==target) return high;
            int mid = int((low+high)/2);
            if(nums[mid]<target){
                low = mid;
            }else if(nums[mid]>target){
                high = mid;
            }else{
                return mid;
            }
            if((low==high-1||low==high)&&nums[low]!=target&&nums[high]!=target)
                return -1;
        }
        return -1;
    }
};
