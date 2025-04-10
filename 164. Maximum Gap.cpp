class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            int n = nums.size();
            if(n < 2) return 0;
            int mn = INT_MAX;
            int mx = INT_MIN;
            for(int i = 0; i < n; ++i){
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            }
            int bucket_size = max(1, (mx - mn) / (n - 1) + 1);
            vector<pair<int, int>> buckets(n, {-1, -1}); // min/max in the bucket
            for(int i = 0; i < n; ++i){
                int idx = (nums[i] - mn) / bucket_size;
                if(buckets[idx].first == -1){
                    buckets[idx].first = buckets[idx].second = nums[i];
                }else{
                    buckets[idx].first = min(buckets[idx].first, nums[i]);
                    buckets[idx].second = max(buckets[idx].second, nums[i]);
                }
            }
            int ret = 0;
            int i = 0;
            while(i < n){
                if(buckets[i].first != -1){
                    ret = max(ret, buckets[i].second - buckets[i].first);
                    int j = i + 1;
                    while(j < n && buckets[j].first == -1){
                        ++j;
                    }
                    if(j < n) ret = max(ret, buckets[j].first - buckets[i].second);
                    i = j - 1;
                }
                ++i;
    
            }
            return ret;
        }
    };