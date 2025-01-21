class TrieNode{
public:
    bool is_end;
    TrieNode* children[26];

    TrieNode(){
        for(int i = 0; i < 26; ++i){
            children[i] = nullptr;
        }
        is_end = false;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto& c : word){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        bool ret = true;
        for(auto& c : word){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto& c : prefix){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */