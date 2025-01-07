class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        seen.insert(n);
        while(n!=1){
            long long next_n = 0;
            while(n>0){
                next_n += (long long)(n%10)*(n%10);
                n /= 10;
            }
            if(seen.count(next_n)) return false;
            seen.insert(next_n);
            n = next_n;
        }
        return true;
    }
};