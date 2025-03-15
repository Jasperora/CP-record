class Solution {
    public:
        int partitionString(string s) {
            unordered_set<char> sc;
            int ret = 1;
            for(auto& c : s){
                if(sc.count(c)){
                    ++ret;
                    sc.clear();
                }
                sc.insert(c);
            }
            return ret;
        }
    };