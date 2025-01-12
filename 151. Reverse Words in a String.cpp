class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v;
        vector<int> pos;
        for(int i = 0; i < s.size(); ++i){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                v.push_back(s[i]);
                pos.push_back(i);
            }
        }
        for(int i = 0; i < pos.size(); ++i){
            s[pos[i]] = v[v.size()-1-i];
        }
        return s;

    }
};