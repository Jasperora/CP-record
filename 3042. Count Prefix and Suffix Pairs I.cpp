class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.length()>str2.length()) return false;
        bool correct = true;
        for(int i = 0; i < str1.length(); ++i){
            correct &= (str1[i]==str2[i]);
            correct &= (str1[i]==str2[i+str2.length()-str1.length()]);
        }
        return correct;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret = 0;
        for(int i = 0; i < words.size()-1; ++i){
            for(int j = i+1; j < words.size(); ++j){
                ret += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return ret;
    }
};