// backtrack
class Solution2 {
public:
    vector<vector<int>> xor_result;
    vector<bool> col;
    int cur, ret;
    int n;
    // like n queens
    void backtrack(int row){
        if(row == n){
            ret = min(ret, cur);
        }else{
            for(int i = 0; i < n; ++i){
                if(col[i])
                    continue;
                col[i] = true;
                cur += xor_result[row][i];
                backtrack(row + 1);
                col[i] = false;
                cur -= xor_result[row][i];
            }
        }
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        xor_result.resize(n, vector<int>(n));
        col.resize(n, false);
        ret = INT_MAX;
        cur = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                xor_result[i][j] = nums1[i] ^ nums2[j];
            }
        }
        // . O . . .
        // . . O . .
        // . . . O .
        // O . . . .
        // . . . . O
        // permutate nums2
        // try all combinations
        backtrack(0);
        return ret;
    }
};