class Solution {
    public:
        int minDifference(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int ret = 2e9;
            int i = 0, j = nums.size()-1;
            if(j<=2) return 0;
            for(int k = 0; k < 4; ++k){
                cout << j-k << ' ' << i+3-k << '\n';
                int amp = nums[j-k] - nums[i+3-k];
                if(amp< ret) ret = amp;
            }
            return ret;
        }
    };