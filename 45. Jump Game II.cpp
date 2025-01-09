class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int cnt = 0, ptr = 0;
        while(ptr<nums.size()-1){
            int max_jump = 0, max_i = ptr;
            cout << ptr+nums[ptr] << '\n';
            if(nums[ptr]+ptr>=nums.size()-1){
                ++cnt;
                break;
            }else{
                for(int i = ptr+1; i <= ptr+nums[ptr]; ++i){
                    if(i+nums[i]>max_jump){
                        max_jump = i+nums[i];
                        max_i = i;
                    }
                }
                
                ptr = max_i;
                ++cnt;
            }
            // cout << ptr << '\n';
        }
        return cnt;
    }
};
