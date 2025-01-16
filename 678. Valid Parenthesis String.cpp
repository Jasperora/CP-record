class Solution {
public:
    bool checkValidString(string s) {
        int open_p_min = 0, open_p_max = 0;
        for(auto& c : s){
            if(c=='('){
                ++open_p_min;
                ++open_p_max;
            }else if(c==')'){
                --open_p_min;
                --open_p_max;
            }else{
                ++open_p_max;
                --open_p_min;
            }
            if(open_p_max<0) return false;
            if(open_p_min<0) open_p_min = 0;
        }
        return open_p_min==0;
    }
};
