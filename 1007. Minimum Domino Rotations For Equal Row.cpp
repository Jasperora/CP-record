class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<bool> dies(7, true);
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= 6; ++j){
                if(!dies[j]) continue;
                dies[j] = dies[j] & (tops[i] == j || bottoms[i] == j);
            }
        }
        int ret = INT_MAX;
        for(int i = 1; i <= 6; ++i){
            if(dies[i]){
                int cnt_top = 0;
                int cnt_bottom = 0;
                int cnt_both = 0;
                for(int j = 0; j < n; ++j){
                    if(tops[j] == i && bottoms[j] == i){
                        ++cnt_top;
                        ++cnt_bottom;
                        ++cnt_both;
                    }else if(tops[j] == i){
                        ++cnt_top;
                    }else if(bottoms[j] == i){
                        ++cnt_bottom;
                    }
                }
                ret = min(ret, min(cnt_top - cnt_both, cnt_bottom - cnt_both));
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};