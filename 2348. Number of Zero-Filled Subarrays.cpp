class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            map<int, int> m;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i]==0){
                    if(i==0 || (nums[i-1]!=0)){
                        int j = i;
                        while(j!=nums.size() && nums[j]==0){
                            ++j;
                        }
                        m[j-i]++;
                    }
                }
            }
            long long ret = 0;
            for(auto& p : m){
                ret += (((long long)p.first*((long long)p.first+1))>>1) * p.second;
            }
            return ret;
        }
    };