class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        while(s!=""){
            bool form_group = false;
            int cnt = 0;
            set<char> sc;
            while(!form_group){
                sc.insert(s[0]);
                s.erase(0, 1);
                ++cnt;
                form_group = true;
                for(auto& c : sc){
                    form_group &= (s.find(c)==string::npos);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
