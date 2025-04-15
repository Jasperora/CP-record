class TrieNode {
public:
    bool is_end;
    TrieNode* zero;
    TrieNode* one;
    TrieNode() {
        is_end = false;
        zero = one = nullptr;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* dummy = new TrieNode();
        for(auto& num : nums){
            // from MSB to LSB
            TrieNode* cur = dummy;
            for(int i = 31; i >= 0; --i){
                if(num & (1 << i)){
                    if(!cur->one){
                        cur->one = new TrieNode();
                    }
                    cur = cur->one;
                }else{
                    if(!cur->zero){
                        cur->zero = new TrieNode();
                    }
                    cur = cur->zero;
                }
            }
            cur->is_end = true;
        }
        int ret = 0;
        for(auto& num : nums){
            TrieNode* cur = dummy;
            int xor_value = 0;
            for(int i = 31; i >= 0; --i){
                if(num & (1 << i)){
                    if(cur->zero){
                        xor_value |= (1 << i);
                        cur = cur->zero;
                    }else{
                        cur = cur->one;
                    }
                }else{
                    if(cur->one){
                        xor_value |= (1 << i);
                        cur = cur->one;
                    }else{
                        cur = cur->zero;
                    }
                }
            }
            ret = max(ret, xor_value);
        }
        return ret;
    }
};