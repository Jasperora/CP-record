class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int start = 0;
        int end = s1.length()-1;
        vector<int> m1(26, 0), m2(26, 0);
        for(auto& c : s1)
            ++m1[c-'a'];
        for(int i = 0; i < s1.length(); ++i)
            ++m2[s2[i]-'a'];
        
        for(int i = 0; i < s2.length()-s1.length(); ++i){
            bool is_perm = true;
            for(int j = 0; j < 26; ++j)
                is_perm &= (m1[j]==m2[j]);
            if(is_perm) return true;
            --m2[s2[i]-'a'];
            ++m2[s2[i+s1.length()]-'a'];
        }
        bool is_perm = true;
        for(int j = 0; j < 26; ++j)
            is_perm &= (m1[j]==m2[j]);
        return is_perm;
    }
};
