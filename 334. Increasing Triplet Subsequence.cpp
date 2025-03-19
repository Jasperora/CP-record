class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            int first, second;
            first = second = INT_MAX;
            for(auto& n : nums){
                if(n<=first) first = n;
                else if(n<=second) second = n;
                else return true;
            }
            return false;
        }
    };