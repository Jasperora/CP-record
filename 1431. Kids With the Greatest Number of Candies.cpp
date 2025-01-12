class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candy = -1;
        for(auto& n : candies){
            max_candy = max(max_candy, n);
        }
        vector<bool> ret;
        ret.resize(candies.size());
        for(int i = 0; i < candies.size(); ++i){
            ret[i] = (bool)(candies[i]+extraCandies>=max_candy);
        }
        return ret;
    }
};