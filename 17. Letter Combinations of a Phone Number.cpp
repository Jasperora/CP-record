class Solution {
public:
    vector<string> ret;
    string comb = "";
    map<char, vector<char> > m;
    void search(int i, const string& digits){
        if(i==digits.size()){
            ret.push_back(comb);
        }
        for(auto & c : m[digits[i]]){
            comb.push_back(c);
            search(i+1, digits);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ret;
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        m['0'] = {'+'};
        search(0, digits);
        return ret;
    }
};
