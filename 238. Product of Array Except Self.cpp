class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int l = nums.size();
            vector<int> ret(l, 1);
            int left_product = 1, right_product = 1;
            for(int i = 0; i < l; ++i){
                ret[i] = left_product;
                left_product *= nums[i];
            }
            for(int i = l-1; i >= 0; --i){
                ret[i] *= right_product;
                right_product *= nums[i];
            }
            return ret;
        }
    };
    