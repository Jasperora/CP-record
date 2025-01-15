class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(auto& t : tasks) ++cnt[t-'A'];
        priority_queue<int> pq;
        for(auto& c : cnt){
            if(c>0) pq.push(c);
        }

        int time = 0;
        queue<pair<int, int> > q;
        while(!q.empty()||!pq.empty()){
            ++time;
            if(!pq.empty()){
                if(pq.top()-1)
                    q.push({pq.top()-1, time+n});
                pq.pop();
            }
            if(!q.empty()&&q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
