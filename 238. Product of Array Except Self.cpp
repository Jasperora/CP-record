class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_cnt = 0;
        int product = 1;
        for(int& n : nums){
            if(n==0) ++zero_cnt;
            else product *= n;
        }
        vector<int> ans;
        if(zero_cnt==0){
            for(int& n : nums){
                ans.push_back(product/n);
            }
        }else if(zero_cnt==1){
            for(int& n : nums){
                if(n==0) ans.push_back(product);
                else ans.push_back(0);
            }
        }else{
            for(int i = 0; i < nums.size(); ++i) ans.push_back(0);
        }
        return ans;
    }
};