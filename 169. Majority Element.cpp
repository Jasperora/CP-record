class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            map<int, int> m;
            for(auto& n : nums){
                m[n]++;
            }
            int ret;
            int max_n = -1;
            for(auto& p : m){
                if(p.second > max_n){
                    max_n = p.second;
                    ret = p.first;
                }
            }
            return ret;
        }
    };