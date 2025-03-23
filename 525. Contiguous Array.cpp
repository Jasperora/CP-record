class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            int cur_sum = 0;
            unordered_map<int, int> m;
            m[0] = 0;
            int ret = 0;
            for(int i = 1; i <= nums.size(); ++i){
                cur_sum += (nums[i-1]==1) ? 1 : -1;
                if(m.count(cur_sum)){
                    ret = max(ret, i-m[cur_sum]);
                }else{
                    m[cur_sum] = i;
                }
            }
            return ret;
        }
        int findMaxLength2(vector<int>& nums) {
            vector<int> pre(nums.size()+1, 0);
            for(int i = 1; i <= nums.size(); ++i){
                pre[i] = pre[i-1] + nums[i-1];
            }
            int start = (nums.size()&1) ? (nums.size()-1) : nums.size();
            for(int i = start; i >= 2; i -= 2){
                for(int j = 0; j+i<=nums.size(); ++j){
                    if(pre[j+i]-pre[j]==(i>>1))
                        return i;
                }
            }
            return 0;
        }
    };