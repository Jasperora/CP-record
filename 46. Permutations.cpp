class Solution {
public:
    vector<vector<int> > ans;
    vector<int> num;
    vector<bool> chosen;
    vector<vector<int>> permute(vector<int>& nums) {
        chosen.resize(nums.size());
        fill(chosen.begin(), chosen.end(), false);
        search(nums);
        return ans;
    }
    void search(vector<int>& nums){
        if(num.size()==chosen.size()) ans.push_back(num);
        for(int i = 0; i < nums.size(); ++i){
            if(chosen[i]) continue;
            num.push_back(nums[i]);
            chosen[i] = true;
            search(nums);
            num.pop_back();
            chosen[i] = false;
        }
    }
};
