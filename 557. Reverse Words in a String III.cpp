class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<char> st;
        string tmp = "";
        for(int i = 0; i < s.length(); ++i){
            if(s[i]!=' ' && i!=s.length()-1) st.push(s[i]);
            else{
                if(i==s.length()-1) st.push(s[i]);
                while(!st.empty()){
                    tmp.push_back(st.top());
                    st.pop();
                }
                ans += tmp;
                if(i!=s.length()-1)
                    ans.push_back(' ');
                tmp = "";
            }
        }
            
        return ans;
    }

    string twoPointerReverseWords(string s) {
        string ans = "";
        int start, end;
        start = end = 0;
        while(end!=s.length()){
            if(s[end]!=' '){
                ++end;
            }else{
                string tmp = "";
                string sub = s.substr(start, end-start);
                for(int i = sub.length()-1; i >= 0; --i){
                    tmp.push_back(sub[i]);
                }
                ans += tmp;
                ans.push_back(' ');
                start = end = end + 1;
            }
        }
        string tmp = "";
        string sub = s.substr(start, end-start);
        for(int i = sub.length()-1; i >= 0; --i){
            tmp.push_back(sub[i]);
        }
        ans += tmp;
        return ans;
    }
};