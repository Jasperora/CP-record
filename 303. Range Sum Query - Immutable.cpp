class NumArray {
    public:
        vector<int> presum;
        NumArray(vector<int>& nums) {
            presum = vector<int>(nums.size(), 0);
            presum[0] = nums[0];
            for(int i = 1; i < nums.size(); ++i){
                presum[i] = nums[i] + presum[i-1];
            }
        }
        
        int sumRange(int left, int right) {
            if(left==0) return presum[right];
            return presum[right]-presum[left-1];
        }
    };
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * int param_1 = obj->sumRange(left,right);
     */