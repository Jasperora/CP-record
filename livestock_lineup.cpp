#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<pair<string, string> > cow_pair;

string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

bool chosen[8];
vector<string> cow_line;

bool has_ans = false;
vector<string> ans;
void search(){
    if(cow_line.size()==8){
        if(!has_ans){
            map<string, int> cow_pos;
            for(int i = 0; i < 8; ++i){
                cow_pos[cow_line[i]] = i;
            }
            bool satisfy = true;
            for(int i = 0; i < N; ++i){
                satisfy &= (abs(cow_pos[cow_pair[i].first]-cow_pos[cow_pair[i].second])==1);
            }
            if(satisfy){
                has_ans = true;
                for(int i = 0; i < 8; ++i){
                    ans.push_back(cow_line[i]);
                }
            }
        }
    }else{
        for(int i = 0; i < 8; ++i){
            if(chosen[i]) continue;
            cow_line.push_back(cows[i]);
            chosen[i] = true;
            search();
            cow_line.pop_back();
            chosen[i] = false;
        }
    }
}

int main(){
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    sort(cows, cows+8);
    
    fin >> N;
    string s[6*N];
    for(int i = 0; i < 6*N; ++i) fin >> s[i];
    cow_pair.resize(N);
    for(int i = 0; i < N; ++i){
        cow_pair[i].first = s[6*i];
        cow_pair[i].second = s[6*i+5];
    }
    search();
    for(int i = 0; i < 8; ++i){
        fout << ans[i] << '\n';
    }
}