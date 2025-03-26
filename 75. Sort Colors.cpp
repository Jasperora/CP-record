class Solution {
    public:
        void sortColors(vector<int>& nums) {
            vector<int> freq(3);
            for(auto& n : nums) ++freq[n];
            int cnt = 0;
            for(int i = 0; i < 3; ++i){
                while(freq[i]--){
                    nums[cnt] = i;
                    ++cnt;
                }
            }
        }
    };