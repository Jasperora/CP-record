class Solution {
    public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            sort(deck.begin(), deck.end());
            dequeue<int> dq;
            for(int i = 0; i < deck.size(); ++i)
                dq.push_back(i);
    
            vector<int> ret(deck.size());
            for(auto& card : deck){
                ret[dq.front()] = card;
                dp.pop_front();
                if(!q.empty()){
                    int top = q.front();
                    q.pop();
                    q.push(top);
                }
            }
    
            return ret;
        }
    };