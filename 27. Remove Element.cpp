class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]==val){
                int j = i+1;
                while(j<nums.size() && nums[j]==val){
                    ++j;
                }
                int ptr =  i;
                int end = j;
                if(end==nums.size()) break;
                while(j<nums.size() && nums[j]!=val && ptr<end){
                    nums[ptr] = nums[j];
                    nums[j] = val;
                    ++ptr;
                    ++j;
                }
                ++cnt;
            }else{
                ++cnt;
            }
        }
        return cnt;
    }
};