class Solution {
    private:
        bool isEnglish(char c){
            return (c>='a'&&c<='z') || (c>='A'&&c<='Z');
        }
        bool isNumeric(char c){
            return c>='0'&&c<='9';
        }
    public:
        bool isPalindrome(string s) {
            int i = 0, j = s.size() - 1;
            int diff = abs('a'-'A');
            while(i<j){
                if(!isEnglish(s[i])&&!isNumeric(s[i])){
                    ++i;
                    continue;
                }
                if(!isEnglish(s[j])&&!isNumeric(s[j])){
                    --j;
                    continue;
                }
                if(s[i]==s[j] || (isEnglish(s[i])&&isEnglish(s[j])&&abs(s[i]-s[j])==diff)){
                    ++i;
                    --j;
                }else {
                    return false;
                }
    
            }
            return true;
        }
    };
    