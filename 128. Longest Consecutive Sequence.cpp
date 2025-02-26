class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> s;
            for(auto& n : nums) s.insert(n);
    
            int ret = 0;
            for(auto& n : s){
                if(!s.count(n-1)){
                    int tmp = n + 1;
                    while(s.count(tmp))
                        ++tmp;
                    ret = max(ret, tmp-n);
                }
            }
            return ret;
        }
    };