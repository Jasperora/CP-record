class Solution {
    public:
        int longestSubarray(vector<int>& nums, int limit) {
            // store index
            deque<int> max_deque;
            deque<int> min_deque;
            int ret = 0;
            int start = 0;
            for(int i = 0; i < nums.size(); ++i){
                while(!max_deque.empty() && nums[max_deque.back()] <= nums[i]){
                    max_deque.pop_back();
                }
                max_deque.push_back(i);
                while(!min_deque.empty() && nums[min_deque.back()] >= nums[i]){
                    min_deque.pop_back();
                }
                min_deque.push_back(i);
                while(nums[max_deque.front()] - nums[min_deque.front()] > limit){
                    ++start;
                    if(max_deque.front() < start) max_deque.pop_front();
                    if(min_deque.front() < start) min_deque.pop_front();
                }
                ret = max(ret, i - start + 1);
            }
            return ret;
        }
    };