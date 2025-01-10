class Solution {
public:
    double myPow(double x, int n) {
        if(n==0||x==1) return 1;
        double ret = 1;
        long long power = n;
        bool negative = false;
        if(power<0){
            negative = true;
            power *= -1;
        }
        while(power){
            if(power&1) ret *= x;
            x = x*x;
            power >>= 1;
        }
        if(negative) ret = 1/ret;
        return ret;
    }
};
