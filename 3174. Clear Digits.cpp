class Solution {
private:
    int hasDigit(string s){
        for(int i = 0; i < s.size(); ++i){
            if(s[i]>='0' && s[i]<='9')
                return i;
        }
        return -1;
    }
public:
    string clearDigits(string s) {
        int tmp = hasDigit(s);
        while(tmp != -1){
            int c_idx;
            for(int i = tmp-1; i >= 0; --i){
                if(s[i]<'0'||s[i]>'9'){
                    c_idx = i;
                    break;
                }
            }
            string new_s;
            for(int i = 0; i < s.size(); ++i){
                if(i==c_idx||i==tmp)
                    continue;
                new_s.push_back(s[i]);
            }
            s = new_s;
            tmp = hasDigit(s);
        }
        return s;
    }
};