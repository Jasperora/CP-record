class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1, 0);
        for(int i = 1; i <= n; i<<=1){
            for(int j = 1; j <= n; ++j){
                if(i&j) ++ret[j];
            }
        }
        return ret;
    }
    vector<int> fasterCountBits(int n) {
        vector<int> ret(n+1, 0);
        ret[0] = 0;
        for(int i = 1; i <= n; ++i){
            ret[i] = ret[i >> 1] + (i&1);
        }
        return ret;
    }
};
