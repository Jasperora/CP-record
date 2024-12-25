#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

vector<string> permutations;
int char_cnt[26];
string s;

void create_permutations(const string & current){
    if(current.size()==s.size()) permutations.push_back(current);
    else{
        for(int i = 0; i < 26; ++i){
            if(char_cnt[i]>0){
                --char_cnt[i];
                create_permutations(current+char('a'+i));
                ++char_cnt[i];
            }
        }
    }
}

int main(){
    cin >> s;
    fill(char_cnt, char_cnt+26, 0);
    for(char c : s) ++char_cnt[c-'a'];

    create_permutations("");
    cout << permutations.size() << '\n';
    for(string p : permutations) cout << p << '\n';

}