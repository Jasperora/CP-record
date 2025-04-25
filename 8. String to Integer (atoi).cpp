class Solution {
    public:
        int myAtoi(string s) {
            int ret = 0;
            bool neg = false;
            bool start = false;
            for(auto& c : s){
                if(!isdigit(c) && c != '+' && c != '-' && c != ' '){
                    break;
                }else if(start && (c == '+' || c == '-' || c == ' ')){
                    break;
                }else if(c == '+' || c == '-'){
                    start = true;
                    if(c == '-')
                        neg = true;
                }else if(c == ' '){
                    if(start) break;
                }else{
                    start = true;
                    if(ret > INT_MAX/10){
                        cout << 'a';
                        if(neg) return INT_MIN;
                        else return INT_MAX;
                    }else{
                        ret *= 10;
                    }
                    if(ret > INT_MAX - (c-'0')){
                        cout << 'b';
                        if(neg) return INT_MIN;
                        else return INT_MAX;
                    }else{
                        ret += (c-'0');
                    }
                }
            }
            if(neg){
                if(ret <= INT_MAX)
                    return -ret;
                else
                    return INT_MIN;
            }
            return ret;
        }
    };