class Solution {
    public:
        int next(int n){
            int ret = 0;
            while(n){
                ret += (n%10) * (n%10);
                n /= 10;
            }
            return ret;
        }
        bool isHappy(int n) {
            int slow = next(n);
            int fast = next(next(n));
            while(fast!=1&&slow!=fast){
                slow = next(slow);
                fast = next(next(fast));
            }
            return fast==1;
        }
    };