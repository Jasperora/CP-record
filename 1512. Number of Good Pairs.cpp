class Solution {
    public:
        int C2(int n){
            return n*(n-1)/2;
        }
        int numIdenticalPairs(vector<int>& nums) {
            map<int, vector<int>> pos;
            for(int i = 0; i < nums.size(); ++i){
                pos[nums[i]].push_back(i);
            }
            int ret = 0;
            for(auto& p : pos){
                ret += C2(p.second.size());
            }
            return ret;
        }
    };