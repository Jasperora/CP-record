class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vs(52, 0), vt(52, 0);
        for(auto& c : t){
            if(c>='a'&&c<='z')
                ++vt[c-'a'];
            else ++vt[c-'A'+26];
        }
        int left = 0, right = 0;
        int min_window_left = 0;
        int min_window_right = s.length()-1;
        bool has_ans = false;
        while(right<s.length()){
            if(s[right]>='a'&&s[right]<='z')
                ++vs[s[right]-'a'];
            else ++vs[s[right]-'A'+26];

            bool contains = true;
            for(int i = 0; i < 52; ++i)
                contains &= (vt[i]<=vs[i]);
            if(contains) has_ans = true;
            while(contains){
                if(right-left<min_window_right-min_window_left){
                    min_window_left = left;
                    min_window_right = right;
                }
                if(s[left]>='a'&&s[left]<='z')
                    --vs[s[left]-'a'];
                else --vs[s[left]-'A'+26];
                ++left;
                contains = true;
                for(int i = 0; i < 52; ++i)
                    contains &= (vt[i]<=vs[i]);
                if(!contains){
                    if(s[left-1]>='a'&&s[left-1]<='z')
                        ++vs[s[left-1]-'a'];
                    else ++vs[s[left-1]-'A'+26];
                    --left;
                }
            }
            ++right;
        }
        if(!has_ans) return "";
        string ret = "";
        for(int i = 0; i < s.length(); ++i){
            if(i>=min_window_left&&i<=min_window_right)
                ret.push_back(s[i]);
        }
        return ret;
    }
};
