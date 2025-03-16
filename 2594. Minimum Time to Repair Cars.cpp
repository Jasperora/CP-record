class Solution {
    public:
        bool canFix(vector<int>& ranks, int cars, long long time){
            long long cnt = 0;
            for(int i = 0; i < ranks.size(); ++i){
                cnt += (long long)sqrt(time/(long long)ranks[i]);
            }
            return cnt >= cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            sort(ranks.begin(), ranks.end());
            long long i = 1;
            long long j = (long long)ranks[0]*cars*cars;
            while(i!=j&&i+1!=j){
                long long time = (i+j)>>1;
                bool b = canFix(ranks, cars, time);
                if(b){
                    j = time;
                }else{
                    i = time;
                }
            }
            if(i==j) return i;
            if(canFix(ranks, cars, i)) return i;
            return j;
        }
    };