class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        
        int ret = 10;
        int unique_digits = 9;
        int available_digits = 9;
        for(int i = 2; i <= n && available_digits; ++i){
            unique_digits *= available_digits;
            ret += unique_digits;
            --available_digits;
        }
        return ret;
    }
};