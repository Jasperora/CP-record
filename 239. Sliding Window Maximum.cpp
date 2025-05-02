// monotonic queue
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // store index
        // monotonic decreasing queue
        // from left to right: nums[left] > nums[right] decreasing
        deque<int> dq;
        int n = nums.size();
        for(int i = 0; i < k; ++i){
            if(dq.empty()){
                dq.push_back(i);
            }else{
                while(!dq.empty() && nums[i] >= nums[dq.back()]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        vector<int> ret(n - k + 1);
        for(int i = k; i < n; ++i){
            ret[i - k] = nums[dq.front()];
            // pop back
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // pop front
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            dq.push_back(i);
        }
        ret.back() = nums[dq.front()];
        return ret;
    }
};
// use count
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        vector<int> cnt(20001, 0);
        int max_in_win = -10001;
        for(int i = 0; i < k; ++i){
            ++cnt[nums[i]+10000];
            if(nums[i]>max_in_win) max_in_win = nums[i];
        }
        ret.push_back(max_in_win);
        for(int i = 1; i <= nums.size()-k; ++i){
            --cnt[nums[i-1]+10000];
            ++cnt[nums[i-1+k]+10000];
            if(nums[i-1]==max_in_win){
                if(nums[i-1+k]>=max_in_win)
                    max_in_win = nums[i-1+k];
                else{
                    for(int j = max_in_win+10000; j >= 0; --j){
                        if(cnt[j]){
                            max_in_win = j - 10000;
                            break;
                        }
                    }
                }
            }else{
                max_in_win = max(max_in_win, nums[i-1+k]);
            }
            ret.push_back(max_in_win);
        }
        return ret;

    }
};