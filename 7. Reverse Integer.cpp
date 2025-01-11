class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        // int INT_MIN = -2147483648;
        // int INT_MAX = 2147483647;
        bool negative = false;
        if(x<0) negative = true;
        if(negative){
            if(x==INT_MIN) return 0;
            else{
                x *= -1;
            }
        }
        while(x){
            int digit = x%10;
            x /= 10;
            if(ret>(int)INT_MAX/10)
                return 0;
            ret *= 10;
            ret += digit;
        }
        if(negative) ret *= -1;
        return ret;
    }
};
