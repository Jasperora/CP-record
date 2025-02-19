class Solution {
    public:
        int numWaterBottles(int numBottles, int numExchange) {
            int ret = 0, emptyBottle = 0;
            while(!(numBottles==0 && emptyBottle<numExchange)){
                ret += numBottles;
                emptyBottle += numBottles;
                numBottles = int(emptyBottle/numExchange);
                emptyBottle %= numExchange;
            }
            ret += numBottles;
            return ret;
        }
    };