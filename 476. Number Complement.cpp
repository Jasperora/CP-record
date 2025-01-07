class Solution {
public:
    int findComplement(int num) {
        int ans = 0, cnt = 0;
        while(num>0){
            int add_num;
            add_num = !(num&1);
            for(int i = 0; i < cnt; ++i)
                add_num <<= 1;
            ans += add_num;
            num >>= 1;
            ++cnt;
        }
        return ans;
    }
};