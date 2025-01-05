class Solution {
public:
    vector<vector<int> > ans;
    vector<int> num;
    vector<vector<int>> subsets(vector<int>& nums) {
        search(0, nums);
        return ans;
    }
    void search(int idx, vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(num);
        }else{
            search(idx+1, nums);
            num.push_back(nums[idx]);
            search(idx+1, nums);
            num.pop_back();
        }
    }
};
