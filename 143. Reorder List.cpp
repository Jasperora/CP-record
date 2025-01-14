/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval& a, Interval& b){
        return a.end < b.end;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        bool visited[intervals.size()];
        fill(visited, visited+intervals.size(), false);
        bool solve = false;
        int ret = 0;
        while(!solve){
            vector<Interval> one_day;
            for(int i = 0; i < intervals.size(); ++i){
                if(!visited[i]){
                    if(one_day.empty()){
                        one_day.push_back(intervals[i]);
                        visited[i] = true;
                    }else{
                        if(intervals[i].start >= one_day.back().end){
                            one_day.push_back(intervals[i]);
                            visited[i] = true;
                        }
                    }
                }
            }
            ++ret;
            solve = true;
            for(auto& b : visited) solve &= b;
        }
        return ret;
    }
};
