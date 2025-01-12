class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]==0){
                int ptr = i;
                int j = i+1;
                while(j<nums.size() && nums[j]==0){
                    ++j;
                }
                int end = j;
                if(end==nums.size()) break;
                while(ptr<end&&j<nums.size()){
                    nums[ptr] = nums[j];
                    nums[j] = 0;
                    ++ptr;
                    ++j;
                }
            }
        }
    }
};