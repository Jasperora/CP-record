class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int cnt = 0;
            for(int i = 0; i < 200; ++i){
                bool is = true;
                for(int j = 0; j < strs.size()-1; ++j){
                    if(strs[j].size()>=cnt+1&&strs[j+1].size()>=cnt+1)
                        is &= strs[j][cnt]==strs[j+1][cnt];
                    else{
                        is = false;
                        break;
                    }
                }
                if(is) ++cnt;
            }
            return strs[0].substr(0, cnt);
        }
    };