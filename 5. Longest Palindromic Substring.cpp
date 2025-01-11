class Solution {
public:
    int checkPalindrome(const string& s, int left, int right){
        while(left>=0&&right<=s.size()-1&&s[left]==s[right]){
            --left;
            ++right;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int M = 0;
        string ret;
        for(int i = 0; i < s.size(); ++i){
            int odd_num = checkPalindrome(s, i, i);
            int even_num = checkPalindrome(s, i, i+1);
            if(odd_num>M){
                ret = s.substr(i-(odd_num>>1), odd_num);
                M = odd_num;
            }
            if(even_num>M){
                ret = s.substr(i-(even_num>>1)+1, even_num);
                M = even_num;
            }
        }
        return ret;
    }
};