class TrieNode{
public:
    bool is_end;
    unordered_map<char, TrieNode*> children;
    TrieNode(){
        is_end = false;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieNode* dummy = new TrieNode();
        vector<string> candidates;
        int longest_word_len = 0;
        sort(words.begin(), words.end());
        for(auto& word : words){
            // add word to Trie
            TrieNode* cur = dummy;
            bool is_candidate = true;
            for(int i = 0; i < word.size(); ++i){
                char c = word[i];
                if(!cur->children.count(c)){
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
                if(i != word.size()-1 && !cur->is_end)
                    is_candidate = false;
            }
            cur->is_end = true;
            if(is_candidate){
                candidates.push_back(word);
                longest_word_len = max(longest_word_len, (int)word.size());
            }
        }
        for(int i = 0; i < candidates.size(); ++i){
            if(candidates[i].size() == longest_word_len)
                return candidates[i];
        }
        return "";
    }
};