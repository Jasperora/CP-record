#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(){
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");

    int N;
    fin >> N;

    vector<pair<string, string> > city_state;
    string city, state;
    for(int i = 0; i < N; ++i){
        fin >> city >> state;
        city_state.push_back(make_pair(city.substr(0, 2), state));
    }

    long long total = 0;
    map<string, int> seen;
    for(const auto& [city, state] : city_state){
        if(city!=state) total += seen[state+city];
        ++seen[city+state];
    }
    fout << total;
}