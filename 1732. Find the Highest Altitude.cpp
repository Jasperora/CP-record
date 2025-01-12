class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0;
        int ret = 0;
        for(auto& n : gain){
            cur += n;
            if(cur>ret) ret = cur;
        }
        return ret;
    }
};