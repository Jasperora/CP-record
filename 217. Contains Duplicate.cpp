class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> seen;
        for(auto & n : nums){
            if(seen[n]) return true;
            else seen[n] = true;
        }
        return false;
    }
};