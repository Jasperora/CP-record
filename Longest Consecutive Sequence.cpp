class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()>1){
            int a = nums[0], b = nums[0];
            int max = 1;
            for(int i = 1; i < nums.size(); ++i){
                if(nums[i]==b+1){
                    ++b;
                    if(b-a+1>max) max = b-a+1;
                }else if(nums[i] > b+1){
                    a = nums[i];
                    b = nums[i];
                }
            }
            return max;
        }else{
            return nums.size();
        }
    }
};
