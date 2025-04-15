class TrieNode{
public:
    vector<string> suggestions;
    unordered_map<char, TrieNode*> children;
    TrieNode(){

    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* dummy = new TrieNode();
        sort(products.begin(), products.end());
        for(auto& product : products){
            TrieNode* cur = dummy;
            for(auto& c : product){
                if(!cur->children.count(c)){
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
                if(cur->suggestions.size() < 3)
                    cur->suggestions.push_back(product);
            }
        }
        vector<vector<string>> ret;
        TrieNode* cur = dummy;
        for(int i = 0; i < searchWord.size(); ++i){
            char c = searchWord[i];
            if(!cur->children.count(c)){
                for(int j = i; j < searchWord.size(); ++j)
                    ret.push_back({});
                return ret;
            }else{
                cur = cur->children[c];
                ret.push_back(cur->suggestions);
            }
        }
        return ret;
    }
};