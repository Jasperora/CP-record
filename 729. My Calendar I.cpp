class MyCalendar {
    public:
        map<int, int> events;
        MyCalendar() {
            
        }
        
        bool book(int startTime, int endTime) {
            auto next_event = events.lower_bound(startTime);
            if(next_event != events.end() && endTime > next_event->first)
                return false;
            if(next_event != events.begin()){
                auto prev_event = prev(next_event);
                if(prev_event->second > startTime)
                    return false;
            }
            events[startTime] = endTime;
            return true;
        }
    };
    
    /**
     * Your MyCalendar object will be instantiated and called as such:
     * MyCalendar* obj = new MyCalendar();
     * bool param_1 = obj->book(startTime,endTime);
     */