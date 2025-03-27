class Solution {
    public:
        int numSplits(string s) {
            unordered_set<char> left, right;
            vector<int> leftCnt(s.size(), 0), rightCnt(s.size(), 0);
            leftCnt.front() = 1;
            left.insert(s.front());
            for(int i = 1; i < s.size(); ++i){
                if(!left.count(s[i])){
                    left.insert(s[i]);
                    leftCnt[i] = leftCnt[i-1] + 1;
                }else{
                    leftCnt[i] = leftCnt[i-1];
                }
            }
            rightCnt.back() = 1;
            right.insert(s.back());
            for(int i = s.size()-2; i >= 0; --i){
                if(!right.count(s[i])){
                    right.insert(s[i]);
                    rightCnt[i] = rightCnt[i+1] + 1;
                }else{
                    rightCnt[i] = rightCnt[i+1];
                }
            }
            int ret = 0;
            for(int i = 0; i < s.size()-1; ++i){
                if(leftCnt[i]==rightCnt[i+1]) ++ret;
            }
            return ret;
        }
    };