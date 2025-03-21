class Solution {
    public:
        int rangeBitwiseAnd(int left, int right) {
            int diff = right-left;
            int ret = left&right;
            int cnt = 0;
            int a = 2147483647;
            while(diff>0){
                ++cnt;
                diff >>= 1;
            }
            for(int _ = 0; _ < cnt; _++){
                a >>= 1;
            }
            for(int _ = 0; _ < cnt; _++){
                a <<= 1;
            }
            return ret&a;
        }
        int rangeBitwiseAnd2(int left, int right) {
            int cnt = 0;
            while(left!=right){
                left >>= 1;
                right >>= 1;
                ++cnt;
            }
            return left << cnt;
        }
    };