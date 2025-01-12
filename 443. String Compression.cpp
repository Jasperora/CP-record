class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0, end = 0, cur = 0;
        while(end!=chars.size()){
            while(end<chars.size() && chars[end]==chars[start]){
                ++end;
            }

            if(end==start+1){
                chars[cur++] = chars[start];
            }else{
                chars[cur++] = chars[start];
                string s = to_string(end-start);
                for(auto& c : s)
                    chars[cur++] = c;
            }
            if(end!=chars.size()){
                start = end;
            }
        }
        return cur;
    }
};