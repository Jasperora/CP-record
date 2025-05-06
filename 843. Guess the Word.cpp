/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int similarity(const string& word1, const string& word2){
        int ret = 0;
        for(int i = 0; i < word1.size(); ++i){
            if(word1[i] == word2[i])
                ++ret;
        }
        return ret;
    }
    string findBestGuess(vector<string>& words){
        // minimax
        // for each word, find the worse case number of words left after guessing this word
        int minimax_size = words.size();
        string ret = "";
        for(auto& word1: words){
            vector<int> count(6, 0);
            for(auto& word2: words){
                if(word2 == word1) continue;
                ++count[similarity(word1, word2)];
            }
            int mx = 0;
            for(int i = 0; i < 6; ++i)
                mx = max(mx, count[i]);
            if(mx < minimax_size){
                minimax_size = mx;
                ret = word1;
            }
        }
        return ret;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        while(true){
            string s = findBestGuess(words);
            int n = master.guess(s);
            if(n == 6) return;
            vector<string> next_words;
            for(auto& word: words){
                if(similarity(word, s) == n)
                    next_words.push_back(word);
            }
            words = next_words;
        }
    }
};