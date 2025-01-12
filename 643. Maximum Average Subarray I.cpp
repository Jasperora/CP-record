class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ret = -10001, avg;
        double sum = 0;
        for(int i = 0; i < k; ++i) sum += nums[i];
        for(int i = k; i < nums.size(); ++i){
            avg = sum/k;
            if(avg>ret) ret = avg;
            sum -= nums[i-k];
            sum += nums[i];
        }
        avg = sum/k;
        if(avg>ret) ret = avg;
        return ret;
    }
};