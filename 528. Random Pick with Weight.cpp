class Solution {
    public:
        int sum = 0;
        vector<int> presum;
        int len;
        Solution(vector<int>& w) {
            len = w.size();
            presum.resize(len);
            for(int i = 0; i < len; ++i){
                sum += w[i];
                if(i == 0) presum[i] = w[i];
                else presum[i] = presum[i - 1] + w[i];
            }
        }
        
        int pickIndex() {
            int r = rand() % sum;
            int left = 0, right = len-1;
            while(left < right){
                int mid = (left + right) >> 1;
                if(r < presum[mid]){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            return left;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(w);
     * int param_1 = obj->pickIndex();
     */