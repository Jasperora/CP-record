class Solution {
public:
    int addDigits(int num) {
        int ans = num, tmp;
        while(ans>=10){
            int tmp = 0;
            while(num>0){
                tmp += num%10;
                num /= 10;
            }
            ans = num = tmp;
        }
        return ans;
    }
    int digitalRootAddDigits(int num){
        if(num==0) return 0;
        else if(num%9) return num%9;
        else return 9;
    }
};