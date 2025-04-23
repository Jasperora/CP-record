class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size(), n2 = text2.size();
            vector<int> prev(n2 + 1, 0), current(n2 + 1, 0);
            for(int i = 0; i < n1; ++i){
                for(int j = 1; j <= n2; ++j){
                    if(text1[i] == text2[j-1])
                        current[j] = prev[j-1] + 1;
                    else current[j] = max(current[j-1], prev[j]);
                }
                swap(prev, current);
            }
            // last swap makes result in prev
            return prev[n2];
        }
    };