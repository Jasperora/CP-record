class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        bool all_nine = true;
        for(auto& d : digits) all_nine &= (d==9);
        if(all_nine) ret.resize(digits.size()+1);
        else ret.resize(digits.size());
        int carry, sum;
        for(int i = digits.size()-1; i >= 0; --i){
            if(i==digits.size()-1){
                sum = 1+digits[i];
            }else{
                sum = carry+digits[i];
            }
            if(sum>=10){
                carry = 1;
                sum -= 10;
            }else carry = 0;
            ret[i] = sum;
        }
        if(carry) ret[0] = 1;
        return ret;
    }
};
