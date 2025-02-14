class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        
        int n1_len = num1.size(), n2_len = num2.size();
        int l = n1_len+n2_len;
        int ans[l];
        fill(ans, ans+l, 0);
        for(int i = n1_len-1; i >= 0; --i){
            for(int j = n2_len-1; j >= 0; --j){
                ans[l-2-i-j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        // for(int i = 0; i < l; ++i){
        //     cout << ans[i] << ' ';
        // }
        // cout << '\n';
        for(int i = 0; i < l; ++i){
            if(ans[i]>=10){
                ans[i+1] += int(ans[i]/10);
                ans[i] %= 10;
            }
        }
        // for(int i = 0; i < n1_len+n2_len; ++i){
        //     cout << ans[i] << ' ';
        // }
        string ret = "";
        bool start = false;
        for(int i = l-1; i >= 0; --i){
            if(ans[i]!=0) start = true;
            if(start) ret.push_back(ans[i]+'0');
        }
        return ret;
    }
};
