class Solution {
    public:
        int kthFactor(int n, int k) {
            vector<int> fac;
            for(int i = 1; i <= n; ++i){
                if(n%i==0) fac.push_back(i);
            }
            if(k>fac.size()) return -1;
            return fac[k-1];
        }
    };