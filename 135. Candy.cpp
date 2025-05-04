class Solution {
public:
    int candy(vector<int>& ratings) {
        // ratings: 1 2 3 4 0 1 2 3
        // candies: 1 2 3 4 1 2 3 4
        int n = ratings.size();
        vector<int> candies(n, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = max(candies[i-1]+1, candies[i]);
            }
        }
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i+1]+1, candies[i]);
            }
        }
        int ret = 0;
        for(auto& c : candies){
            // cout << c << ' ';
            ret += c;
        }
        return ret;
    }
};