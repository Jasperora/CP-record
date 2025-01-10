class Solution {
public:
    int getSum(int a, int b) {
        int tmp = a;
        a = (a&b)<<1; // carry
        b = tmp^b; // sum
        // a+b == (a&b)<<1 + tmp^b
        while(a & b){
            // keep doing this while carry and sum are "separated"
            tmp = a;
            a = (a&b)<<1;
            b = tmp^b;
        }
        // if a and b are "separated", a+b == a|b
        return a|b;
    }
};
