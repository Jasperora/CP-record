class Solution {
    public:
        int maxEvents(vector<vector<int>>& events) {
            // sort by start time
            sort(events.begin(), events.end());
            // use pq to store end time
            // attend the event that has earliest end time
            priority_queue<int, vector<int>, greater<int>> minHeap;
            int day = events[0][0];
            int ret = 0;
            size_t i = 0;
            while(!minHeap.empty() || i < events.size()){
                while(i < events.size() && events[i][0] <= day){
                    minHeap.push(events[i][1]);
                    ++i;
                }
                // remove all events that cannot be attended
                while(!minHeap.empty() && minHeap.top() < day){
                    minHeap.pop();
                }
                if(!minHeap.empty()){
                    minHeap.pop();
                    ++ret;
                }
                ++day;
            }
            return ret;
        }
    };