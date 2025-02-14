class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool has_endWord = false;
        for(auto& word : wordList){
            if(word==endWord){
                has_endWord = true;
                break;
            }
        }
        map<string, vector<string> > neighbors;
        if(!has_endWord) return 0;

        wordList.push_back(beginWord);
        int l = beginWord.size();
        for(auto& word : wordList){
            for(int i = 0; i < l; ++i){
                string pattern = word.substr(0, i);
                pattern.push_back('*');
                if(i+1 < l)
                    pattern += word.substr(i+1, l-i-1);
                neighbors[pattern].push_back(word);
            }
        }
        // for(map<string, vector<string> >::iterator it = neighbors.begin(); it != neighbors.end(); ++it){
        //     cout << it->first << ": ";
        //     for(auto& word : neighbors[it->first]){
        //         cout << word << ',';
        //     }
        //     cout << '\n';
        // }
        set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int ret = 1;
        while(!q.empty()){
            int q_len = q.size();
            ++ret;
            while(q_len--){
                string cur = q.front();
                q.pop();
                for(int i = 0; i < l; ++i){
                    string pattern = cur.substr(0, i);
                    pattern.push_back('*');
                    if(i+1 < l)
                        pattern += cur.substr(i+1, l-i-1);
                    for(auto& word : neighbors[pattern]){
                        if(word==endWord) return ret;
                        if(!visited.count(word)){
                            // cout << word << ' ' << ret << '\n';
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
