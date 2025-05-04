class Solution {
public:
    int ret = 0;
    void recursiveSort(const vector<int>& nums, vector<int>& sorted, int start, int end){
        if(start >= end) return;
        int mid = (start + end) >> 1;
        // after calling recursiveSort for [start, mid] amd [mid+1, end]
        // the count in them have been added to ret
        // not only need to count the pairs whose one element is in [start, mid]
        // while the other element is in [mid+1, end]
        recursiveSort(nums, sorted, start, mid);
        recursiveSort(nums, sorted, mid+1, end);

        for(int j = mid+1; j <= end; ++j){
            auto iter = upper_bound(sorted.begin() + start, sorted.begin() + mid + 1, 2 * (long long)(sorted[j]));
            ret += sorted.begin() + mid - iter + 1;
        }
        int i = start, j = mid+1, idx = 0;
        vector<int> temp(end - start + 1);
        while(i <= mid && j <= end){
            if(sorted[i] < sorted[j]){
                temp[idx] = sorted[i];
                ++i;
            }
            else{
                temp[idx] = sorted[j];
                ++j;
            }
            ++idx;
        }
        while(i <= mid){
            temp[idx] = sorted[i];
            ++i;
            ++idx;
        }
        while(j <= end){
            temp[idx] = sorted[j];
            ++j;
            ++idx;
        }
        for(int i = start; i <= end; ++i){
            sorted[i] = temp[i - start];
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        recursiveSort(nums, sorted, 0, n-1);
        return ret;
    }
};