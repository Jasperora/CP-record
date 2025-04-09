class Solution {
    public:
        int calculate(string s) {
            stack<int> nums;
    
            int n = s.size();
            int curNum = 0;
            char curOp = '+';
            int ret = 0;
            for(int i = 0; i < n; ++i){
                if(isdigit(s[i])){
                    curNum = curNum * 10 + (s[i] - '0');
                }
                if(!isdigit(s[i]) && s[i] != ' ' || i == n-1){
                    if(curOp == '+'){
                        ret += curNum;
                        nums.push(curNum);
                    }else if(curOp == '-'){
                        ret -= curNum;
                        nums.push(-curNum);
                    }else if(curOp=='*'){
                        ret -= nums.top();
                        nums.top() *= curNum;
                        ret += nums.top();
                    }else{
                        ret -= nums.top();
                        nums.top() /= curNum;
                        ret += nums.top();
                    }
                    curOp = s[i];
                    curNum = 0;
                }
            }
            return ret;
        }
    };