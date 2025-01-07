class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        set<vector<int> > seen;
        int i = 0;
        for(int i = 0; i < nums.size()-2; ++i){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]>-nums[i]) --k;
                else if(nums[j]+nums[k]<-nums[i]) ++j;
                else{
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    sort(tmp.begin(), tmp.end());
                    if(!seen.count(tmp)){
                        ans.push_back(tmp);
                        seen.insert(tmp);
                    }
                    --k;
                    ++j;
                }
            }
        }
        return ans;

    }
};
