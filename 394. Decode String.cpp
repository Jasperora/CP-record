class Solution {
    public:
        int idx = 0;
        string recursive(const string& s, int& i){
            string ret = "";
            while(i < s.size() && s[i] != ']'){
                if(!isdigit(s[i])){
                    ret.push_back(s[i++]);
                }else{
                    int num = 0;
                    while(isdigit(s[i])){
                        num *= 10;
                        num += s[i] - '0';
                        ++i;
                    }
                    // omit [
                    ++i;
                    string sub = recursive(s, i);
                    while(num--){
                        ret += sub;
                    }
                    // omit ]
                    ++i;
                }
            }
            return ret;
        }
        string decodeString(string s) {
            return recursive(s, idx);
        }
        string decodeString2(string s) {
            int i = 0;
            stack<string> resStack;
            stack<int> cntStack;
            string cur = "";
            while(i < s.size()){
                if(isdigit(s[i])){
                    int num = 0;
                    while(isdigit(s[i])){
                        num *= 10;
                        num += s[i] - '0';
                        ++i;
                    }
                    cntStack.push(num);
                }else if(s[i] == '['){
                    resStack.push(cur);
                    ++i;
                    cur = "";
                }else if(s[i] == ']'){
                    string tmp = resStack.top();
                    resStack.pop();
                    int cnt = cntStack.top();
                    cntStack.pop();
                    while(cnt--){
                        tmp += cur;
                    }
                    cur = tmp;
                    ++i;
                }else{
                    cur.push_back(s[i]);
                    ++i;
                }
            }
            return cur;
        }
    };