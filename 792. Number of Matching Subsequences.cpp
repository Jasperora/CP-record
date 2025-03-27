class Solution {
    public:
        int numMatchingSubseq(string s, vector<string>& words) {
            vector<vector<int>> vv(26);
            for(int i = 0; i < s.size(); ++i){
                vv[s[i]-'a'].push_back(i);
            }
            int ret = 0;
            for(auto& w : words){
                vector<int> cnt(26, 0);
                int cur = -1;
                bool isSub = true;
                for(int i = 0; i < w.size(); ++i){
                    int c_num = w[i]-'a';
                    while(cnt[c_num] < vv[c_num].size() && cur >= vv[c_num][cnt[c_num]]){
                        ++cnt[c_num];
                    }
                    if(cnt[c_num]==vv[c_num].size()){
                        isSub = false;
                        break;
                    }else{
                        cur = vv[c_num][cnt[c_num]];
                    }
                }
                ret += isSub;
            }
            return ret;
        }
    };