class StockPrice {
    public:
        map<int, int> time_price;
        map<int, int> price_cnt;
        StockPrice() {
    
        }
        
        void update(int timestamp, int price) {
            if(time_price.count(timestamp)){
                --price_cnt[time_price[timestamp]];
                if(price_cnt[time_price[timestamp]] == 0){
                    auto it = price_cnt.find(time_price[timestamp]);
                    price_cnt.erase(it);
                }
            }
            time_price[timestamp] = price;
            ++price_cnt[price];
        }
        
    
        int current() {
            auto back = time_price.end();
            return prev(back)->second;
        }
        
        int maximum() {
            auto back = price_cnt.end();
            return prev(back)->first;
        }
        
        int minimum() {
            auto front = price_cnt.begin();
            return front->first;
        }
    };
    
    /**
     * Your StockPrice object will be instantiated and called as such:
     * StockPrice* obj = new StockPrice();
     * obj->update(timestamp,price);
     * int param_2 = obj->current();
     * int param_3 = obj->maximum();
     * int param_4 = obj->minimum();
     */