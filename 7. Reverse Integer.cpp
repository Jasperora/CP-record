class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool negative = x<0;
        if(x>2147483647||x<-2147483647) return 0;
        x = abs(x);
        long long tmp;
        while(x>0){
            tmp = (long long)(ans)*10;
            if(tmp>2147483647) return 0;
            ans *= 10;
            ans += x % 10;
            x = (x-(x%10))/10;
        }
        if(negative) ans *= -1;
        return ans;
    }
};