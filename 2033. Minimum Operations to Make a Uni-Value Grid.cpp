class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> v;
            for(auto& vi : grid){
                for(auto& n : vi) v.push_back(n);
            }
            sort(v.begin(), v.end());
            int mid = (v.size()&1) ? (v.size()>>1)+1 : v.size()>>1;
            int ret = 0;
            for(int i = 0; i < v.size(); ++i){
                int diff = abs(v[mid-1]-v[i]);
                if(diff%x) return -1;
                ret += diff/x;
            }
            return ret;
        }
    };