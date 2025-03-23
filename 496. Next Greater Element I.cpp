class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<pair<int, int>> sp;
            vector<int> record(nums2.size());
            unordered_map<int, int> m;
            for(int i = nums2.size()-1; i >= 0; --i){
                m[nums2[i]] = i;
                if(sp.empty()) {
                    sp.push({i, nums2[i]});
                    record[i] = -1;
                }
                else{
                    if(nums2[i]>=sp.top().second){
                        sp.pop();
                        while(!sp.empty()&&sp.top().second<=nums2[i])
                            sp.pop();
                        if(!sp.empty()) record[i] = sp.top().first;
                        else record[i] = -1;
                        sp.push({i, nums2[i]});
                    }else{
                        record[i] = sp.top().first;
                        sp.push({i, nums2[i]});
                    }
                }
            }
            vector<int> ret;
            for(auto& n : nums1){
                if(record[m[n]]==-1) ret.push_back(-1);
                else ret.push_back(nums2[record[m[n]]]);
            }
            return ret;
        }
    };