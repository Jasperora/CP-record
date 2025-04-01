class Solution {
    public:
        string removeDuplicateLetters(string s) {
            unordered_map<char, int> freq;
            for(auto& c : s) ++freq[c];
    
            stack<char> st;
            vector<bool> seen(26, false);
            for(int i = 0; i < s.size(); ++i){
                --freq[s[i]];
                if(st.empty()){
                    st.push(s[i]);
                    seen[s[i]-'a'] = true;
                }else{
                    if(!seen[s[i]-'a']){
                        while(!st.empty() && int(s[i])<int(st.top()) && freq[st.top()]!=0){
                            seen[st.top()-'a'] = false;
                            st.pop();
                        }
                        st.push(s[i]);
                        seen[s[i]-'a'] = true;
                    }
                }
            }
            string ret = "";
            while(!st.empty()){
                ret.push_back(st.top());
                st.pop();
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
    };