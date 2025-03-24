class Solution {
    public:
        bool isPossible(vector<int>& nums) {
            unordered_map<int, int> freq, need;
            for(auto& n : nums){
                freq[n]++;
            }
            for(auto& n : nums){
                if(freq[n]==0) continue;
                freq[n]--;
                if(need[n]>0){
                    need[n]--;
                    need[n+1]++;
                }else if(freq[n+1]>0 && freq[n+2]>0){
                    freq[n+1]--;
                    freq[n+2]--;
                    need[n+3]++;
                }else return false;
            }
            return true;
        }
    };