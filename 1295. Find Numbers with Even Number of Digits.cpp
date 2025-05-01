class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(auto& n : nums){
            if(int(log10(n)) & 1)
                ++ret;
        }
        return ret;
    }
};