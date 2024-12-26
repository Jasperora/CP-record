#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    int N;
    fin >> N;
    map<string, int> cows;

    string cow_names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for(int i = 0; i < 7; ++i) cows[cow_names[i]] = 0;

    string name;
    int milk;
    for(int i = 0; i < N; ++i){
        fin >> name >> milk;
        cows[name] += milk;
    }

    int M;
    bool find_M = false;
    for(int i = 0; i < 10001; ++i){
        for(const auto& c : cows){
            if(i==c.second){
                M = c.second;
                find_M = true;
                break;
            }
        }
        if(find_M) break;
    }

    int min_cnt = 0;
    map<string, int> reduced_cows;
    for(const auto& c : cows){
        if(c.second!=M) reduced_cows[c.first] = c.second;
    }
    if(reduced_cows.size()==0){
        fout << "Tie";
        return 0;
    }
    int second_last;
    bool find_second_last = false;
    for(int i = M+1; i < 10001; ++i){
        for(const auto& c : reduced_cows){
            if(i==c.second){
                second_last = c.second;
                find_second_last = true;
                break;
            }
        }
        if(find_second_last) break;
    }
    vector<string> second_last_cows;
    for(const auto& c : reduced_cows){
        if(c.second==second_last) second_last_cows.push_back(c.first);
    }
    if(second_last_cows.size()>1){
        fout << "Tie";
        return 0;
    }
    fout << second_last_cows[0];
}