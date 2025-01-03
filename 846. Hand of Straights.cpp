class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        bool used[hand.size()];
        fill(used, used+hand.size(), false);
        for(int i = 0; i < hand.size(); ++i){
            if(!used[i]){
                int cnt = 0;
                for(int j=i; j < hand.size(); ++j){
                    if(hand[j]==hand[i]+cnt && !used[j]){
                        used[j] = true;
                        ++cnt;
                        if(cnt==groupSize) break;
                    }
                }
                if(cnt<groupSize) return false;
            }
        }
        return true;
    }
};
