#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    map<int, vector<int> > record_pos;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        m[a] = x - a;
        record_pos[a].push_back(i + 1);
    }
    for(const auto &it : m){
        if(it.first != it.second){
            if(!record_pos[it.second].empty()){
                int first = record_pos[it.first][0];
                int second = record_pos[it.second][0];
                if(first < second) cout << first << ' ' << second;
                else cout << second << ' ' << first;
                return 0;
            }
        }else{
            if(record_pos[it.first].size() > 1){
                int first = record_pos[it.first][0];
                int second = record_pos[it.first][1];
                if(first < second) cout << first << ' ' << second;
                else cout << second << ' ' << first;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}