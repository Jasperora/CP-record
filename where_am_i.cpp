#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main(){
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    int N;
    fin >> N;
    string s;
    fin >> s;
    
    set<string> ss;
    int cnt;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < N-i+1; ++j){
            string sub = s.substr(j, i);
            if(ss.count(sub)==0){
                ss.insert(sub);
            }else{
                cnt = i + 1;
            }
        }
    }
    fout << cnt;
    
}