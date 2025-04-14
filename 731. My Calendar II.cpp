class MyCalendarTwo {
    public:
        vector<pair<int, int>> events;
        vector<pair<int, int>> overlap;
        MyCalendarTwo() {
            
        }
        
        bool book(int startTime, int endTime) {
            for(auto& p : overlap){
                if(!(p.first >= endTime || startTime >= p.second))
                    return false;
            }
            for(auto& e : events){
                if(max(e.first, startTime) < min(e.second, endTime)){
                    overlap.push_back({max(e.first, startTime), min(e.second, endTime)});
                }
            }
            events.push_back({startTime, endTime});
            return true;
        }
    };
    
    /**
     * Your MyCalendarTwo object will be instantiated and called as such:
     * MyCalendarTwo* obj = new MyCalendarTwo();
     * bool param_1 = obj->book(startTime,endTime);
     */