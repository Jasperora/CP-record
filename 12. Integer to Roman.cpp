class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while(num>=1000){
            num -= 1000;
            ans.push_back('M');
        }
        while(num>=100){
            if(int(num/100)==9){
                ans += "CM";
                num -= 900;
            }else if(int(num/100)==4){
                ans += "CD";
                num -= 400;
            }else{
                if(int(num/100)>=5){
                    ans.push_back('D');
                    num -= 500;
                }
                for(int i = 0; i < int(num/100); ++i){
                    ans.push_back('C');
                    num -= 100;
                }
            }
        }
        while(num>=10){
            if(int(num/10)==9){
                ans += "XC";
                num -= 90;
            }else if(int(num/10)==4){
                ans += "XL";
                num -= 40;
            }else{
                if(int(num/10)>=5){
                    ans.push_back('L');
                    num -= 50;
                }
                for(int i = 0; i < int(num/10); ++i){
                    ans.push_back('X');
                    num -= 10;
                }
            }
        }
        while(num>0){
            if(num==9){
                ans += "IX";
                num = 0;
            }else if(num==4){
                ans += "IV";
                num = 0;
            }else{
                if(num>=5){
                    ans.push_back('V');
                    num -= 5;
                }
                for(int i = 0; i < num; ++i) ans.push_back('I');
                num = 0;
            }
        }
        return ans;
    }
};