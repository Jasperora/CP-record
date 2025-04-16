class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using pii = pair<int, vector<int>>;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        for(int i = 0; i < k, i < nums1.size(); ++i){
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }
        vector<vector<int>> ret;
        int n2 = nums2.size();
        while(ret.size() < k){
            auto [sum, p] = minHeap.top();
            minHeap.pop();
            int i = p[0], j = p[1];
            ret.push_back({nums1[i], nums2[j]});
            // after {i, j} are checked to be current min
            // add {i, j + 1}
            // not add {i + 1, j} since it was added at first or don't need
            if(j + 1 < n2)
                minHeap.push({nums1[i] + nums2[j+ 1], {i, j + 1}});
        }
        return ret;
    }
};