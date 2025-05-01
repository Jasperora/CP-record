class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int word_len = words[0].size();
        if(s.size() < n * word_len) return {};
        vector<int> ret;
        unordered_map<string, int> words_num;
        for(auto& word: words){
            ++words_num[word];
        }
        unordered_map<string, int> cur_words_num;
        
        int len_s = s.size();
        for(int i = 0; i < word_len; ++i){
            int left = i;
            int count = 0;
            cur_words_num.clear();
            for(int right = i; right <= len_s - word_len; right += word_len){
                string word = s.substr(right, word_len);
                if(words_num.count(word)){
                    ++cur_words_num[word];
                    ++count;
                    while(cur_words_num[word] > words_num[word]){
                        string delete_word = s.substr(left, word_len);
                        left += word_len;
                        --count;
                        --cur_words_num[delete_word];
                    }
                    if(count == n){
                        ret.push_back(left);
                    }
                }else{
                    cur_words_num.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }
        return ret;
    }
};