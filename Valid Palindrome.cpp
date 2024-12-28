class Solution {
public:
    bool isPalindrome(string s) {
        string reduced_s = "";
        for(auto& c : s){
            if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
                if(c>='A'&&c<='A'+26){
                    c -= ('A'-'a');
                }
                reduced_s.push_back(c);
            }
        }
        bool ans = true;
        for(int i = 0; 2*i < reduced_s.size(); ++i){
            ans &= (reduced_s[i]==reduced_s[reduced_s.size()-1-i]);
        }
        return ans;
    }
};
