#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

int main(){
    ifstream fin("guess.in");
    ofstream fout("guess.out");

    int N;
    fin >> N;
    string animals[N];
    map<string, set<string> > animal_characteristic;
    for(int i = 0; i < N; ++i){
        fin >> animals[i];
        int K;
        fin >> K;
        string characteristic;
        for(int j = 0; j < K; ++j){
            fin >> characteristic;
            animal_characteristic[animals[i]].insert(characteristic);
        }
    }
    // for(auto& p : animal_characteristic){
    //     cout << p.first << ": ";
    //     for(auto& s : p.second) cout << s << ' ';
    //     cout << '\n';
    // }
    int ans = -1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(i!=j){
                int tmp = 0;
                for(auto& s : animal_characteristic[animals[i]]){
                    tmp += animal_characteristic[animals[j]].count(s);
                }
                if(tmp > ans) ans = tmp;
            }
        }
    }
    fout << ans+1;

}