class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for(int i = 0; i < flowerbed.size(); ++i){
            bool can_place = (flowerbed[i]!=1);
            if(i!=0) can_place &= (flowerbed[i-1]!=1);
            if(i!=flowerbed.size()-1) can_place &= (flowerbed[i+1]!=1);
            if(can_place){
                flowerbed[i] = 1;
                ++cnt;
            }
        }
        return cnt>=n;
    }
};