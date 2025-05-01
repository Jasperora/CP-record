// sliding window
// use only one hashmap
class Solution1 {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> target_map;
        for(auto& c : t)
            ++target_map[c];
        int len = INT_MAX;
        int ret_left = 0;
        int left = 0;
        int need_cnt = target_map.size();
        for(int right = 0; right < s.size(); ++right){
            if(target_map.count(s[right])){
                --target_map[s[right]];
                if(need_cnt){
                    if(target_map[s[right]] == 0){
                        --need_cnt;
                    }
                }
                if(!need_cnt){
                    while(!target_map.count(s[left]) || (target_map.count(s[left]) && target_map[s[left]] < 0)){
                        // this condition means that we don't need s[left]
                        // to make this substring satisfy
                        if(target_map.count(s[left]))
                            ++target_map[s[left]];
                        ++left;
                    }
                    if(len > right - left + 1){
                        ret_left = left;
                        len = right - left + 1;
                    }
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(ret_left, len);
    }
};
// sliding window
// use a count to check instead of checking the whole hashmap
class Solution2 {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> target_map;
        for(auto& c : t)
            ++target_map[c];
        int min_window_left = 0, min_window_right = s.size();
        int left = 0;
        unordered_map<char, int> cur_map;
        bool has_ans = false;
        int have_cnt = 0;
        for(int right = 0; right <= s.size(); ++right){
            if(target_map.count(s[right])){
                ++cur_map[s[right]];
                if(cur_map[s[right]] == target_map[s[right]])
                    ++have_cnt;
                // s[left:right+1] is current substring
                // its length is right - left + 1
                
                if(have_cnt == target_map.size()){
                    while(left < right && (!target_map.count(s[left]) || cur_map[s[left]] > target_map[s[left]])){
                        if(cur_map.count(s[left]))
                            --cur_map[s[left]];
                        ++left;
                    }
                    if(right - left + 1 <= min_window_right - min_window_left){
                        min_window_left = left;
                        min_window_right = right + 1;
                        has_ans = true;
                    }
                }
            }

        }
        return has_ans ? s.substr(min_window_left, min_window_right - min_window_left) : "";
    }
};
// brute force sliding window
// check the whole hashmap each time
class Solution3 {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> target_map;
        for(auto& c : t)
            ++target_map[c];
        int min_window_left = 0, min_window_right = s.size();
        int left = 0;
        unordered_map<char, int> cur_map;
        bool has_ans = false;
        for(int right = 0; right <= s.size(); ++right){
            if(target_map.count(s[right])){
                ++cur_map[s[right]];
                // s[left:right+1] is current substring
                // its length is right - left + 1
                if(right - left + 1 < t.size())
                    continue;
                bool satisfy = true;
                for(auto& [c, cnt] : target_map){
                    if(!cur_map.count(c) || cur_map[c] < cnt){
                        // not satisfy
                        satisfy = false;
                        break;
                    }
                }
                if(satisfy){
                    while(left < right && (!target_map.count(s[left]) || cur_map[s[left]] > target_map[s[left]])){
                        if(cur_map.count(s[left]))
                            --cur_map[s[left]];
                        ++left;
                    }
                    if(right - left + 1 <= min_window_right - min_window_left){
                        min_window_left = left;
                        min_window_right = right + 1;
                        has_ans = true;
                    }
                }
            }

        }
        return has_ans ? s.substr(min_window_left, min_window_right - min_window_left) : "";
    }
};