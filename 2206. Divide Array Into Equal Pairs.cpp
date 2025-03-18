class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            map<int, int> m;
            for(auto& n : nums){
                m[n]++;
            }
            for(auto& p : m){
                if(p.second&1) return false;
            }
            return true;
        }
    };