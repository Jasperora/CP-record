#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string S, T;
    fin >> S >> T;
    string censored;

    for(int i = 0; i < S.size(); ++i){
        censored += S[i];
        if(censored.size() >= T.size() && censored.substr(censored.size()-T.size(), censored.size()) == T) {
            censored.resize(censored.size()-T.size());
        }
    }
    fout << censored;
}