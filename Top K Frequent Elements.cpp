class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> nums_cnt;
        for(int &n : nums) {
            if(!nums_cnt.count(n)) nums_cnt[n] = 0;
            ++nums_cnt[n];
        }
        vector<pair<int, int> > nums_freq;
        for(auto& p : nums_cnt){
            nums_freq.push_back(make_pair(p.second, p.first));
        }
        sort(nums_freq.begin(), nums_freq.end());

        vector<int> ans;
        for(int i = 0; i < nums_freq.size(); ++i){
            if(i>=nums_freq.size()-k){
                ans.push_back(nums_freq[i].second);
            }
        }
        return ans;
    }
};
