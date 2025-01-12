class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int dp[nums.size()][nums.size()];
        for(int i = 0; i < nums.size(); ++i){
            if(i!=0&&i!=nums.size()-1){
                dp[i][i] = nums[i-1]*nums[i]*nums[i+1];
            }else if(i==0){
                dp[i][i] = nums[i]*nums[i+1];
            }else{
                dp[i][i] = nums[i-1]*nums[i];
            }
            for(int j = 0; j < i; ++j)
                dp[i][j] = 0;
        }
        for(int i = 1; i <= nums.size()-1; ++i){
            for(int j = 0; j+i < nums.size(); ++j){
                dp[j][j+i] = 0;
                for(int k = j; k <= j+i; ++k){
                    // burst k last
                    int burst_k_coins = nums[k];
                    if(j-1>=0) burst_k_coins *= nums[j-1];
                    if(j+i+1<nums.size()) burst_k_coins *= nums[j+i+1];

                    int coins = burst_k_coins;
                    if(k-1>=0) coins += dp[j][k-1];
                    if(k+1<nums.size()) coins += dp[k+1][j+i];
                    // cout << j << ' ' << j+i << ": " << coins << '\n';
                    dp[j][j+i] = max(dp[j][j+i], coins);
                }
            }
        }

        return  dp[0][nums.size()-1];
    }
};
