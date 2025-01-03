class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump_pos = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i+nums[i]>max_jump_pos)
                max_jump_pos = i+nums[i];
            else if(i==max_jump_pos && nums[i]==0 && max_jump_pos<nums.size()-1)
                return false;
            if(max_jump_pos >= nums.size())
                return true;
        }
        return true;
    }
};
