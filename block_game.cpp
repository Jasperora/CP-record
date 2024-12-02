#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int N;
    fin >> N;
    string words[N][2];
    for(int i = 0; i < N; ++i) fin >> words[i][0] >> words[i][1];

    int char_cnt[N][26][2];
    int max_char_cnt[N][26];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 26; ++j){
            char_cnt[i][j][0] = char_cnt[i][j][1] = 0;
            max_char_cnt[i][j] = 0;
        }
    }

    for(int i = 0; i < N; ++i){
        for(char& c: words[i][0]){
            ++char_cnt[i][int(c-'a')][0];
        }
        for(char& c: words[i][1]){
            ++char_cnt[i][int(c-'a')][1];
        }
        for(int j = 0; j < 26; ++j){
            max_char_cnt[i][j] = max(char_cnt[i][j][0], char_cnt[i][j][1]);
        }
    }


    int ans[26];
    for(int i = 0; i < 26; ++i){
        ans[i] = 0;
        for(int j = 0; j < N; ++j){
            ans[i] += max_char_cnt[j][i];
        }
    }
    for(int i = 0; i < 26; ++i){
        fout << ans[i] << '\n';
    }
}