class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            queue<int> q;
            for(int i = 0; i < tickets.size(); ++i){
                q.push(i);
            }
            int ret = 1;
            while(true){
                if(q.front()==k&&tickets[k]==1) break;
                int ppl = q.front();
                q.pop();
                --tickets[ppl];
                if(tickets[ppl]>0) q.push(ppl);
                ++ret;
            }
            return ret;
        }
        int timeRequiredToBuy2(vector<int>& tickets, int k) {
            int ret = 0;
            int target = tickets[k];
            for(int i = 0; i < tickets.size(); ++i){
                if(i==k) continue;
                if(tickets[i]<target) ret += tickets[i];
                else ret += (i<k) ? target : target-1;
            }
            ret += target;
            return ret;
        }
    };