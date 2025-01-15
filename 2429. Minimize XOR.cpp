class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bit_cnt_1 = 0, bit_cnt_2 = 0;
        int tmp1 = num1, tmp2 = num2;
        while(num1){
            bit_cnt_1 += num1 & 1;
            num1 >>= 1;
        }
        while(num2){
            bit_cnt_2 += num2 & 1;
            num2 >>= 1;
        }
        if(bit_cnt_2==bit_cnt_1){
            return tmp1;
        }else if(bit_cnt_2<bit_cnt_1){
            int bit_cnt = bit_cnt_1 - bit_cnt_2;
            int shift_cnt = 0;
            while(bit_cnt){
                bit_cnt -= tmp1 & 1;
                tmp1 >>= 1;
                ++shift_cnt;
            }
            while(shift_cnt--){
                tmp1 <<= 1;
            }
            return tmp1;
        }else{
            int bit_cnt = bit_cnt_2 - bit_cnt_1;
            int bit = 1;
            while(bit_cnt){
                if(!(tmp1&bit)){
                    tmp1 += bit;
                    --bit_cnt;
                }
                bit <<= 1;
            }
            return tmp1;
        }

    }
};