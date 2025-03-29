class RecentCounter {
    public:
        queue<int> store;
        RecentCounter() {
            
        }
        
        int ping(int t) {
            store.push(t);
            while(store.front()<t-3000) store.pop();
            return store.size();
        }
    };
    
    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter* obj = new RecentCounter();
     * int param_1 = obj->ping(t);
     */