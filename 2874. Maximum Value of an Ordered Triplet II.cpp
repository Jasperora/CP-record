#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll> premax(n, 0);
        vector<ll> sufmax(n, 0);
        for(int i = 1; i < n; ++i){
            premax[i] = max(premax[i-1], (ll)nums[i-1]);
        }
        for(int i = n-2; i >= 0; --i){
            sufmax[i] = max(sufmax[i+1], (ll)nums[i+1]);
        }
        ll ret = 0;
        for(int i = 1; i < n-1; ++i){
            ret = max(ret, (premax[i]-(ll)nums[i])*sufmax[i]);
        }
        return ret;
    }
};