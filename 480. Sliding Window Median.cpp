// multiset
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int n = nums.size();
        vector<double> ret(n - k + 1);
        for(int i = 0; i < k; ++i){
            s.insert(nums[i]);
        }

        int half = k >> 1;
        for(int i = k; i < n; ++i){
            if(k & 1){
                ret[i-k] = (double)*(next(s.begin(), half));
            }else{
                double a = (double)*(next(s.begin(), half - 1));
                double b = (double)*(next(s.begin(), half));
                ret[i-k] = (a + b) / 2;
            }
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
        }
        if(k & 1){
            ret.back() = (double)*(next(s.begin(), half));
        }else{
            double a = (double)*(next(s.begin(), half - 1));
            double b = (double)*(next(s.begin(), half));
            ret.back() = (a + b) / 2;
        }
        return ret;
    }
};