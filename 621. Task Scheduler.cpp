class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            priority_queue<int> maxHeap;
            vector<int> cnt(26);
            for(auto& task : tasks)
                ++cnt[task-'A'];
            for(int i = 0; i < 26; ++i){
                if(cnt[i] > 0){
                    maxHeap.push(cnt[i]);
                }
            }
            int time = 0;
            // store the task that needs to wait
            // {count left, time to go back to minHeap}
            queue<pair<int, int>> waiting;
            while(!maxHeap.empty() || !waiting.empty()){
                if(!maxHeap.empty()){
                    if(maxHeap.top() - 1 > 0){
                        waiting.push({maxHeap.top() - 1, time + n});
                    }
                    maxHeap.pop();
                }
                if(!waiting.empty() && waiting.front().second == time){
                    maxHeap.push(waiting.front().first);
                    waiting.pop();
                }
                ++time;
            }
            return time;
        }
        int leastInterval2(vector<char>& tasks, int n) {
            vector<int> cnt(26);
            for(auto& task : tasks)
                ++cnt[task-'A'];
            int max_freq = 0;
            for(int i = 0; i < 26; ++i)
                max_freq = max(max_freq, cnt[i]);
            int max_freq_cnt = 0;
            for(int i = 0; i < 26; ++i){
                if(cnt[i] == max_freq)
                    ++max_freq_cnt;
            }
            // left for the case of no empty slots
            // right for the casae of having empty slots
            return max((int)tasks.size(), (max_freq - 1) * (n + 1) + max_freq_cnt);
        }
    };