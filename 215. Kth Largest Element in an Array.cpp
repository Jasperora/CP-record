class Solution {
    public:
        int quickSelect(vector<int>& nums, int left, int right, const int& k){
            int pivot = left;
            for(int i = left; i < right; ++i){
                if(nums[i] <= nums[right]){
                    if(i != pivot) swap(nums[i], nums[pivot]);
                    ++pivot;
                }
            }
            swap(nums[right], nums[pivot]);
            if(pivot > k){
                return quickSelect(nums, left, pivot - 1, k);
            }else if(pivot < k){
                return quickSelect(nums, pivot + 1, right, k);
            }else return pivot;
        }
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            k = n - k;
            int left = 0, right = n - 1;
            return nums[quickSelect(nums, left, right, k)];
        }
        int findKthLargest2(vector<int>& nums, int k) {
            priority_queue<int> pq;
            for(auto& n : nums){
                pq.push(-n);
                if(pq.size() > k) pq.pop();
            }
            return -pq.top();
        }
    };