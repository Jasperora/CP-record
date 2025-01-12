class Solution {
public:
    bool check(const vector<int>& piles, const int &h, const int& speed){
        int time = 0;
        for(auto&n : piles){
            time += (int)(n/speed) + bool(n%speed);
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 0;
        for(auto & n : piles) end = max(end, n);
        while(start!=end-1){
            int mid = (start+end)>>1;
            bool satisfy = check(piles, h, mid);
            if(satisfy){
                end = mid;
            }else{
                start = mid;
            }
        }
        if(check(piles, h, start)) return start;
        else return end;
    }
};
